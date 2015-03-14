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

        Emitter particles;

        public int particleSprite = -1;
        public bool spawning;
  
        public bool running
        {
            get;//{ return running; }

            set;//{ running = value; }
        }
        public ParticleEditor()
        {
            InitializeComponent();
        }

        public void Initialize()
        {
            running = true;
            spawning = false;
            draw = SGP.CSGP_Direct3D.GetInstance();
            textures = SGP.CSGP_TextureManager.GetInstance();

            draw.Initialize(GraphicsPanel, false);
            draw.AddRenderTarget(GraphicsPanel);

            textures.Initialize(draw.Device, draw.Sprite);

            particleSprite = textures.LoadTexture("../../particleJacob.png");
        }

        public void Update(float _elapsedTime)
        {

         
        }

        public void Render()
        {
            draw.Clear(GraphicsPanel, Color.Black);
            draw.DeviceBegin();
            draw.SpriteBegin();

            {
                //textures.Draw(particleSprite, 300, 300);
                //draw.DrawLine(10, 10, 100, 100, Color.Aqua, 5);

                
            }

            draw.SpriteEnd();
            draw.DeviceEnd();
            draw.Present();
            
        }


        public void Terminate()
        {
            particles.particlesAlive.Clear();
            particles.particlesDead.Clear();
        }


        public void CreateParticle()
        {

            if(particles.particlesDead.Count >= particles.spawnRate)
            {


            }
            else
            {
                Particle particle = new Particle();

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
            public List<Particle> particlesAlive = new List<Particle>();
            public List<Particle> particlesDead = new List<Particle>();

            public int posX
            {
                get;
                set;
            }

            public int posY
            {
                get;
                set;
            }

            public int spreadMin
            {
                get;
                set;
            }

            public int spreadMax
            {
                get;
                set;
            }

            public int width
            {
                get;
                set;
            }

            public int height
            {
                get;
                set;
            }

            public int spawnRate
            {
                get;
                set;
            }
        }

        public class Particle
        {

            public int sprite
            {
                get;
                set;
            }
 
 
            public float currLife
            {
                get;
                set;
            }

            public int colorAlphaCurr
            {
                get;
                set;
            }

            public int colorRedCurr
            {
                get;
                set;
            }

            public int colorGreenCurr
            {
                get;
                set;
            }

            public int colorBlueCurr
            {
                get;
                set;
            }

            public int colorAlphaCurr
            {
                get;
                set;
            }

            public int colorAlphaCurr
            {
                get;
                set;
            }

            public float scaleCurr
            {
                get;
                set;
            }

            public int velCurr
            {
                get;
                set;
            }

            public int rotationCurr
            {
                get;
                set;
            }

        }
    }
}
