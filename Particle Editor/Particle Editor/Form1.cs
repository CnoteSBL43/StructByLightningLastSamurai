using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace Particle_Editor
{
    public partial class ParticleEditor : Form
    {
        SGP.CSGP_Direct3D draw = null;
        SGP.CSGP_TextureManager textures = null;

        Color bgColor;
        Color start;
        Color end;

        Size spriteSize;

        ColorDialog colorStart = null;
        ColorDialog colorEnd = null;

        Emitter particles = new Emitter();

        Point spawnRectPoint;
        Size spawnRectSize;
        Color spawnRectColor;
        Rectangle particleSpawn;

        Random rand = new Random();

        public int particleSprite = -1;
        private bool mouseMove;
        private bool spawning;
        private bool changed;

        public float currentTime;
        public float prevTime;
        public float elapsedTime;
        public float spawnTime;

        private bool running;
        public bool Running
        {
            get { return running; }
            set { running = value; }
        }

        public ParticleEditor()
        {
            InitializeComponent();
        }

        public void Initialize()
        {
            running = true;
            changed = true;
            spawning = true;
            bloomButton.Enabled = false;

            draw = SGP.CSGP_Direct3D.GetInstance();
            textures = SGP.CSGP_TextureManager.GetInstance();

            bgColor = Color.Black;

            start = Color.Magenta;
            end = Color.FromArgb(0, Color.Blue);

            draw.Initialize(GraphicsPanel, false);
            draw.AddRenderTarget(GraphicsPanel);

            textures.Initialize(draw.Device, draw.Sprite);

            if (particleSprite == -1)
            {
                particleSprite = textures.LoadTexture("../../Sparkle.png");
            }

            spriteSize.Width = textures.GetTextureWidth(particleSprite);
            spriteSize.Height = textures.GetTextureHeight(particleSprite);

            spawnRectPoint.X = GraphicsPanel.Size.Width / 2;
            spawnRectPoint.Y = GraphicsPanel.Size.Height / 2;

            spawnRectSize.Width = 50;
            spawnRectSize.Height = 50;

            spawnRectColor = Color.Aqua;
            particleSpawn = new Rectangle(spawnRectPoint, spawnRectSize);
            mouseMove = false;

            emitterRectXPosNum.Value = spawnRectPoint.X;
            emitterRectYPosNum.Value = spawnRectPoint.Y;

            emitterRectWidthNum.Value = spawnRectSize.Width;
            emitterRectHeightNum.Value = spawnRectSize.Height;

            CurrentTimer.Start();
            currentTime = 0;
            elapsedTime = 0;
            prevTime = 0;
            spawnTime = 0.100f;

            particles.particlesAlive = new List<Particle>();
            particles.particlesDead = new List<Particle>();
            particles.SpawnRate = (int)spawnRateNum.Value;
            spawnRateNum.Maximum = maximumPNum.Value;
            maxLifeNum.Minimum = minLifeNum.Value;
            minLifeNum.Maximum = maxLifeNum.Value;
            //particles.PosX = rand.Next(spawnRectPoint.X, (spawnRectPoint.X + (spawnRectSize.Width/2)));
            //particles.PosY = rand.Next(spawnRectPoint.Y, (spawnRectPoint.Y + (spawnRectSize.Height / 2)));
            particles.PosX = spawnRectPoint.X;// +(spawnRectSize.Width / 2);
            particles.PosY = spawnRectPoint.Y;// +(spawnRectSize.Height / 2);
        }

        public void Update()
        {

            elapsedTime = currentTime - prevTime;
            prevTime = currentTime;

            spawnTime -= elapsedTime;

            particleSpawn.X = spawnRectPoint.X;
            particleSpawn.Y = spawnRectPoint.Y;
            particleSpawn.Width = spawnRectSize.Width;
            particleSpawn.Height = spawnRectSize.Height;

            particles.PosX = spawnRectPoint.X; //+(spawnRectSize.Width / 2);
            particles.PosY = spawnRectPoint.Y; //+(spawnRectSize.Height / 2);

            if (spawning)
            {
                if (particles.particlesAlive.Count < maximumPNum.Value)
                {
                    CreateParticle();
                }
                if (continuousCheck.Checked == false)
                {
                    if (particles.particlesAlive.Count >= spawnRateNum.Value)
                        spawning = false;
                }
            }

           

            for (int i = 0; i < particles.particlesAlive.Count; i++)
            {
                particles.particlesAlive[i].CurrLife -= elapsedTime;
                if (particles.particlesAlive[i].CurrLife <= 0)
                {
                    particles.particlesAlive.RemoveAt(i--);
                }
                else
                {
                    particles.particlesAlive[i].CurrPosX += (int)((float)particles.particlesAlive[i].VelCurrX * elapsedTime);
                    particles.particlesAlive[i].CurrPosY += (int)((float)particles.particlesAlive[i].VelCurrY * elapsedTime);

                    float partLifeProg = (particles.particlesAlive[i].MaxLife - particles.particlesAlive[i].CurrLife) / particles.particlesAlive[i].MaxLife;
                    particles.particlesAlive[i].ScaleCurr = (((float)scaleEndNum.Value - (float)scaleStartNum.Value) * partLifeProg) + (float)scaleStartNum.Value;

                    particles.particlesAlive[i].RotationCurr = ToRadians((((float)rotEndNum.Value - (float)rotStartNum.Value) * partLifeProg) + (float)rotStartNum.Value);

                    float color = (((float)end.A - (float)start.A) * partLifeProg) + (float)start.A;
                    particles.particlesAlive[i].ColorAlphaCurr = (int)color;

                    color = (((float)end.R - (float)start.R) * partLifeProg) + (float)start.R;
                    particles.particlesAlive[i].ColorRedCurr = (int)color;

                    color = (((float)end.G - (float)start.G) * partLifeProg) + (float)start.G;
                    particles.particlesAlive[i].ColorGreenCurr = (int)color;

                    color = (((float)end.B - (float)start.B) * partLifeProg) + (float)start.B;
                    particles.particlesAlive[i].ColorBlueCurr = (int)color;
                }
            }
        }

        public void Render()
        {
            draw.Clear(GraphicsPanel, bgColor);
            draw.DeviceBegin();
            draw.SpriteBegin();

            {
                draw.DrawHollowRect(particleSpawn, spawnRectColor, 5);

                for (int i = 0; i < particles.particlesAlive.Count; i++)
                {
                    float rotCenterX = particles.particlesAlive[i].CurrPosX + (particles.particlesAlive[i].ScaleCurr * (spriteSize.Width / 2));
                    float rotCenterY = particles.particlesAlive[i].CurrPosY + (particles.particlesAlive[i].ScaleCurr * (spriteSize.Height / 2));

                    textures.Draw(particles.particlesAlive[i].Sprite, particles.particlesAlive[i].CurrPosX, particles.particlesAlive[i].CurrPosY,
                                    particles.particlesAlive[i].ScaleCurr, particles.particlesAlive[i].ScaleCurr, Rectangle.Empty, rotCenterX, rotCenterY,
                                    particles.particlesAlive[i].RotationCurr, Color.FromArgb(particles.particlesAlive[i].ColorAlphaCurr, particles.particlesAlive[i].ColorRedCurr,
                                    particles.particlesAlive[i].ColorGreenCurr, particles.particlesAlive[i].ColorBlueCurr));
                }
            }

            draw.SpriteEnd();
            draw.DeviceEnd();
            draw.Present();
        }

        public void Terminate()
        {
            //particles.particlesAlive.Clear();
            //particles.particlesDead.Clear();
            CurrentTimer.Stop();
        }


        public float ToRadians(float degree)
        {
            return (float)(Math.PI / 180) * degree;
        }

        public void CreateParticle()
        {

            //if(particles.particlesDead.Count >= particles.SpawnRate)
            //{


            //}
            //else
            if(spawnTime <= 0)
            {
                for (int i = 0; i < spawnRateNum.Value; i++)
                {
                    Particle particle = new Particle();
                    float randMaxLife = rand.Next((int)(minLifeNum.Value * 10), (int)(maxLifeNum.Value * 10));
                    particle.Sprite = particleSprite;
                    particle.MaxLife = (randMaxLife / 10);
                    particle.CurrLife = particle.MaxLife;
                    particle.CurrPosX = particles.PosX + rand.Next(0, (int)emitterRectWidthNum.Value);//((int)particleSpreadNum.Value * 2)) - (int)particleSpreadNum.Value);
                    particle.CurrPosY = particles.PosY + rand.Next(0, (int)emitterRectHeightNum.Value);//((int)particleSpreadNum.Value * 2)) - (int)particleSpreadNum.Value);
                    particle.ScaleCurr = (float)scaleStartNum.Value;
                    particle.RotationCurr = 0;
                    particle.ColorAlphaCurr = start.A;
                    particle.ColorRedCurr = start.R;
                    particle.ColorGreenCurr = start.G;
                    particle.ColorBlueCurr = start.B;

                    int randX = 0;
                    while (randX == 0)
                    {
                        randX = rand.Next((int)velocityXNegNum.Value, (int)velocityXPosNum.Value);
                    }
                    particle.VelCurrX = randX;

                    int randY = 0;
                    while (randY == 0)
                    {
                        randY = rand.Next((int)velocityYNegNum.Value, (int)velocityYPosNum.Value);
                    }
                    particle.VelCurrY = randY;

                    particles.particlesAlive.Add(particle);
                }
                spawnTime = 0.100f;
            }
        }

        public void DeadParticle()
        {


        }

        private void ParticleEditor_FormClosing(object sender, FormClosingEventArgs e)
        {
            running = false;
        }

        public class Emitter
        {
            public List<Particle> particlesAlive;
            public List<Particle> particlesDead;

            private int posX;

            public int PosX
            {
                get { return posX; }
                set { posX = value; }
            }

            private int posY;

            public int PosY
            {
                get { return posY; }
                set { posY = value; }
            }

            private int spreadMin;
            public int SpreadMin
            {
                get { return spreadMin; }
                set { spreadMin = value; }
            }

            public int spreadMax
            {
                get { return spreadMax; }
                set { spreadMax = value; }
            }

            private int width;
            public int Width
            {
                get { return width; }
                set { width = value; }
            }

            private int height;
            public int Height
            {
                get { return height; }
                set { height = value; }
            }

            private int spawnRate;
            public int SpawnRate
            {
                get { return spawnRate; }
                set { spawnRate = value; }
            }
        }

        public class Particle
        {

            private int sprite;
            public int Sprite
            {
                get { return sprite; }
                set { sprite = value; }
            }

            private float maxLife;

            public float MaxLife
            {
                get { return maxLife; }
                set { maxLife = value; }
            }

            private int currPosX;
            public int CurrPosX
            {
                get { return currPosX; }
                set { currPosX = value; }
            }

            private int currPosY;
            public int CurrPosY
            {
                get { return currPosY; }
                set { currPosY = value; }
            }

            private float currLife;
            public float CurrLife
            {
                get { return currLife; }
                set { currLife = value; }
            }

            private int colorAlphaCurr;
            public int ColorAlphaCurr
            {
                get { return colorAlphaCurr; }
                set { colorAlphaCurr = value; }
            }
            private int colorRedCurr;
            public int ColorRedCurr
            {
                get { return colorRedCurr; }
                set { colorRedCurr = value; }
            }

            private int colorGreenCurr;
            public int ColorGreenCurr
            {
                get { return colorGreenCurr; }
                set { colorGreenCurr = value; }
            }


            private int colorBlueCurr;
            public int ColorBlueCurr
            {
                get { return colorBlueCurr; }
                set { colorBlueCurr = value; }
            }

            private float scaleCurr;
            public float ScaleCurr
            {
                get { return scaleCurr; }
                set { scaleCurr = value; }
            }
            private int velCurrX;

            public int VelCurrX
            {
                get { return velCurrX; }
                set { velCurrX = value; }
            }

            private int velCurrY;

            public int VelCurrY
            {
                get { return velCurrY; }
                set { velCurrY = value; }
            }

            private float rotationCurr;
            public float RotationCurr
            {
                get { return rotationCurr; }
                set { rotationCurr = value; }
            }

        }

        private void GraphicsPanel_MouseUp(object sender, MouseEventArgs e)
        {
            if (changed)
            {
                spawnRectColor = Color.Aqua;
            }
            else
            {
                spawnRectColor = bgColor;
            }
            mouseMove = false;
        }

        private void GraphicsPanel_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left && particleSpawn.Contains(e.Location))
            {
                if (changed)
                {
                    spawnRectColor = Color.AntiqueWhite;
                }
                else
                {
                    spawnRectColor = bgColor;
                }
                mouseMove = true;
            }
        }

        private void GraphicsPanel_MouseMove(object sender, MouseEventArgs e)
        {

            if (mouseMove)
            {
                spawnRectPoint.X = e.Location.X - spawnRectSize.Width / 2;
                spawnRectPoint.Y = e.Location.Y - spawnRectSize.Height / 2;

                emitterRectXPosNum.Value = spawnRectPoint.X;
                emitterRectYPosNum.Value = spawnRectPoint.Y;
            }
        }

        private void emitterRectWidthNum_ValueChanged(object sender, EventArgs e)
        {
            spawnRectSize.Width = (int)emitterRectWidthNum.Value;
        }

        private void emitterRectHeightNum_ValueChanged(object sender, EventArgs e)
        {
            spawnRectSize.Height = (int)emitterRectHeightNum.Value;
        }

        private void emitterRectXPos_ValueChanged(object sender, EventArgs e)
        {
            spawnRectPoint.X = (int)emitterRectXPosNum.Value;
        }

        private void emitterRectYPos_ValueChanged(object sender, EventArgs e)
        {
            spawnRectPoint.Y = (int)emitterRectYPosNum.Value;
        }


        private void loadImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "All Files|*.*|BMP Files|*.bmp|JPG Files|*.jpg|PNG Files|*.png";


            if (DialogResult.OK == dlg.ShowDialog())
            {
                particleSprite = textures.LoadTexture(dlg.FileName);

                spriteSize.Width = textures.GetTextureWidth(particleSprite);
                spriteSize.Height = textures.GetTextureHeight(particleSprite);

                for (int i = 0; i < particles.particlesAlive.Count; i++)
                {
                    particles.particlesAlive[i].Sprite = particleSprite;
                }
            }
        }

        private void CurrentTimer_Tick(object sender, EventArgs e)
        {
            currentTime += .100f;
        }

        private void minLifeNum_ValueChanged(object sender, EventArgs e)
        {
            maxLifeNum.Minimum = minLifeNum.Value;
        }

        private void maxLifeNum_ValueChanged(object sender, EventArgs e)
        {
            minLifeNum.Maximum = maxLifeNum.Value;
        }


        private void colorStartButton_Click(object sender, EventArgs e)
        {
            if (colorStart == null)
            {
                colorStart = new ColorDialog();

                colorStart.Text = "Color Start";

                colorStart.AlphaNum = start.A;
                colorStart.RedNum = start.R;
                colorStart.GreenNum = start.G;
                colorStart.BlueNum = start.B;

                colorStart.ColorDialogOK_Click += colorStart_ColorDialogOK_Click;

                colorStart.FormClosed += colorStart_FormClosed;

                colorStart.Show(this);
            }

        }

        void colorStart_ColorDialogOK_Click(object sender, EventArgs e)
        {
            start = Color.FromArgb(colorStart.AlphaNum, colorStart.RedNum, colorStart.GreenNum, colorStart.BlueNum);
        }

        void colorStart_FormClosed(object sender, FormClosedEventArgs e)
        {
            colorStart = null;
        }

        private void colorEndButton_Click(object sender, EventArgs e)
        {
            if (colorEnd == null)
            {
                colorEnd = new ColorDialog();

                colorEnd.Text = "Color End";

                colorEnd.AlphaNum = end.A;
                colorEnd.RedNum = end.R;
                colorEnd.GreenNum = end.G;
                colorEnd.BlueNum = end.B;

                colorEnd.ColorDialogOK_Click += colorEnd_ColorDialogOK_Click;

                colorEnd.FormClosed += colorEnd_FormClosed;

                colorEnd.Show(this);
            }
        }

        void colorEnd_ColorDialogOK_Click(object sender, EventArgs e)
        {
            end = Color.FromArgb(colorEnd.AlphaNum, colorEnd.RedNum, colorEnd.GreenNum, colorEnd.BlueNum);
        }

        void colorEnd_FormClosed(object sender, FormClosedEventArgs e)
        {
            colorEnd = null;
        }

        private void showRectCheck_CheckedChanged(object sender, EventArgs e)
        {
            if (showRectCheck.Checked)
            {
                changed = true;
                spawnRectColor = Color.Aqua;
            }
            else
            {
                changed = false;
                spawnRectColor = bgColor;
            }
        }

        private void continuousCheck_CheckedChanged(object sender, EventArgs e)
        {
            if(continuousCheck.Checked)
            {
                spawning = true;
                bloomButton.Enabled = false;
            }
            else
            {
                spawning = false;
                bloomButton.Enabled = true;
            }
        }

        private void bloomButton_Click(object sender, EventArgs e)
        {
            spawning = true;
            if (particles.particlesAlive.Count > 0)
                particles.particlesAlive.Clear();
        }

        private void maximumPNum_ValueChanged(object sender, EventArgs e)
        {
            spawnRateNum.Maximum = maximumPNum.Value;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void aboutToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            ParticleEditorAbout about = new ParticleEditorAbout();
            about.ShowDialog();
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
