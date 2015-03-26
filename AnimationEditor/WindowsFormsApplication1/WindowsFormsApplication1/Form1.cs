using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        #region Members
        public bool isLooping;
        bool FrameLoop;
        bool isPaused;
        int spritesheetimg = -1;
        bool isDown = false, DrawingFrameRect = false, DrawingCollisionRect = false, DrawingAnchorPoint = false, DrawingParticlePt = false;
        int initialX, initialY;
        Rectangle FrameRect = Rectangle.Empty;
        Rectangle CollisionRect = Rectangle.Empty;
        public Rectangle AnchorPt = new Rectangle(0, 0, 0, 0);
        public Rectangle ParticlePt = new Rectangle(0, 0, 0, 0);
        int FRed = 0, FGreen = 0, FBlue = 255;
        int CRed = 255, CGreen = 0, CBlue = 0;
        int ARed = 0, AGreen = 0, ABlue = 0;
        int PRed = 0, PGreen = 255, PBlue = 0;
        Size spritesize = Size.Empty;
        Size Camera = Size.Empty;
        Point CameraCenter = Point.Empty;
        float Timer;
        float animationtime;
        public bool IsLooping
        {
            get { return isLooping; }
            set { isLooping = value; }
        }

        SGP.CSGP_Direct3D DXDraw = null;
        SGP.CSGP_TextureManager TextureManager;
        SGP.CSGP_Direct3D DXAnimDraw = null;
        #endregion

        public Form1()
        {
            InitializeComponent();
            this.Focus();
            this.DoubleBuffered = true;
            UpdateScrollBars();
        }

        public void Initialize()
        {
            DXDraw = SGP.CSGP_Direct3D.GetInstance();
            TextureManager = SGP.CSGP_TextureManager.GetInstance();
            DXAnimDraw = SGP.CSGP_Direct3D.GetInstance();
            DXDraw.Initialize(SpritePanel, false);
            DXDraw.Initialize(AnimationPanel, false);
            DXDraw.AddRenderTarget(SpritePanel);
            DXAnimDraw.AddRenderTarget(AnimationPanel);
            TextureManager.Initialize(DXDraw.Device, DXDraw.Sprite);
            TextureManager.Initialize(DXAnimDraw.Device, DXAnimDraw.Sprite);
            isLooping = true;
            isPaused = true;
            FrameListBox.SelectedIndex = -1;
            Camera = SpritePanel.Size;
            CameraCenter = new Point(0, 0);
            Timer = 0;
            animationtime = 0.7f;
            timer1.Start();
        }

        public void update()
        {
            UpdateScrollBars();

        }

        #region Rendering
        public void RenderTop()
        {
            DXDraw.Clear(SpritePanel, Color.FromArgb(255, 255, 255, 255));
            DXDraw.DeviceBegin();
            DXDraw.SpriteBegin();
            {
                if (isPaused == false)
                {
                    FrameRect = Rectangle.Empty;
                    CollisionRect = Rectangle.Empty;
                    AnchorPt = Rectangle.Empty;
                    ParticlePt = Rectangle.Empty;
                }

                if (spritesheetimg != -1)
                    TextureManager.Draw(spritesheetimg, 0 - CameraCenter.X, 0 - CameraCenter.Y);
                Rectangle throwaway = Rectangle.Empty;

                throwaway.X = FrameRect.X - CameraCenter.X;
                throwaway.Y = FrameRect.Y - CameraCenter.Y;
                throwaway.Width = FrameRect.Width;
                throwaway.Height = FrameRect.Height;

                DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, FRed, FGreen, FBlue), 2);

                throwaway.X = CollisionRect.X - CameraCenter.X;
                throwaway.Y = CollisionRect.Y - CameraCenter.Y;
                throwaway.Width = CollisionRect.Width;
                throwaway.Height = CollisionRect.Height;

                DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, CRed, CGreen, CBlue), 2);

                throwaway.X = AnchorPt.X - CameraCenter.X;
                throwaway.Y = AnchorPt.Y - CameraCenter.Y;
                throwaway.Width = AnchorPt.Width;
                throwaway.Height = AnchorPt.Height;
                DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, ARed, AGreen, ABlue), 2);

                throwaway.X = ParticlePt.X - CameraCenter.X;
                throwaway.Y = ParticlePt.Y - CameraCenter.Y;
                throwaway.Width = ParticlePt.Width;
                throwaway.Height = ParticlePt.Height;
                DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, PRed, PGreen, PBlue), 2);

                for (int i = 0; i < FrameListBox.Items.Count; i++)
                {

                    Frames temp = (Frames)FrameListBox.Items[i];

                    throwaway.X = temp.Framerect.X - CameraCenter.X;
                    throwaway.Y = temp.Framerect.Y - CameraCenter.Y;
                    throwaway.Width = temp.Framerect.Width;
                    throwaway.Height = temp.Framerect.Height;
                    DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, FRed, FGreen, FBlue), 2);

                    throwaway.X = temp.Collisionrect.X - CameraCenter.X;
                    throwaway.Y = temp.Collisionrect.Y - CameraCenter.Y;
                    throwaway.Width = temp.Collisionrect.Width;
                    throwaway.Height = temp.Collisionrect.Height;
                    DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, CRed, CGreen, CBlue), 2);

                    throwaway.X = temp.Anchorpt.X - CameraCenter.X;
                    throwaway.Y = temp.Anchorpt.Y - CameraCenter.Y;
                    throwaway.Width = temp.Anchorpt.Width;
                    throwaway.Height = temp.Anchorpt.Height;
                    DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, ARed, AGreen, ABlue), 2);

                    throwaway.X = temp.particlept.X - CameraCenter.X;
                    throwaway.Y = temp.particlept.Y - CameraCenter.Y;
                    throwaway.Width = temp.particlept.Width;
                    throwaway.Height = temp.particlept.Height;
                    DXDraw.DrawHollowRect(throwaway, Color.FromArgb(255, PRed, PGreen, PBlue), 2);
                }
            }
            DXDraw.SpriteEnd();
            DXDraw.DeviceEnd();
            DXDraw.Present();
        }

        public void RenderBottom()
        {
            DXAnimDraw.Clear(AnimationPanel, Color.FromArgb(255, 255, 255, 255));
            DXAnimDraw.DeviceBegin();
            DXAnimDraw.SpriteBegin();

            {

                if (FrameListBox.Items.Count > 0)
                {
                    if (Timer >= animationtime && FrameLoop)
                    {
                        if (FrameListBox.SelectedIndex < FrameListBox.Items.Count - 1 && FrameListBox.SelectedIndex != -1)
                        {
                            FrameListBox.SelectedIndex++;
                        }
                        else
                        {
                            FrameListBox.SelectedIndex = 0;
                        }
                        Timer = 0.0f;
                    }
                    if (!FrameLoop && Timer >= animationtime)
                    {
                        if (FrameListBox.SelectedIndex < FrameListBox.Items.Count - 1 && FrameListBox.SelectedIndex != -1)
                        {
                            FrameListBox.SelectedIndex++;
                        }
                        else if (FrameListBox.SelectedIndex > FrameListBox.Items.Count - 1)
                        {
                            FrameListBox.SelectedIndex = -1;
                        }
                        Timer = 0.0f;
                    }
                    if (spritesheetimg != -1 && FrameListBox.SelectedIndex != -1)
                    {
                        Frames tempframe = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                        TextureManager.Draw(spritesheetimg, AnimationPanel.Size.Width / 2, AnimationPanel.Size.Height / 2, 1, 1, tempframe.Framerect);
                    }
                }
            }

            DXAnimDraw.SpriteEnd();
            DXAnimDraw.DeviceEnd();
            DXAnimDraw.Present();
        }
        public void Render()
        {

            RenderTop();
            RenderBottom();
        }
        #endregion

        public void Terminate()
        {
            timer1.Stop();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            isLooping = false;
        }

        #region Mouse

        private void SpritePanel_MouseDown(object sender, MouseEventArgs e)
        {
            isDown = true;
            initialX = e.Location.X + CameraCenter.X;
            initialY = e.Location.Y + CameraCenter.Y;
            if (!DrawingFrameRect && !DrawingCollisionRect && !DrawingParticlePt && DrawingAnchorPoint)
            {
                AnchorPt = new Rectangle(e.X - CameraCenter.X, e.Y - CameraCenter.Y, 1, 1);
                AnchorXUpDown.Value = initialX;
                AnchorYUpDown.Value = initialY;
                this.Invalidate();
            }
            if (!DrawingFrameRect && !DrawingCollisionRect && !DrawingAnchorPoint && DrawingParticlePt)
            {
                ParticlePt = new Rectangle(e.X - CameraCenter.X, e.Y - CameraCenter.Y, 1, 1);
                ParticlePtXUpDown.Value = initialX;
                ParticlePtYUpDown.Value = initialY;
                this.Invalidate();
            }
        }

        private void SpritePanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDown == true)
            {
                if (DrawingFrameRect)
                {

                    int width = e.X - initialX, height = e.Y - initialY;
                    if (Math.Min(initialX, e.X) >= 0 && Math.Min(initialY, e.Y) >= 0)
                        FrameRect = new Rectangle(Math.Min(initialX, e.X + CameraCenter.X), Math.Min(initialY, e.Y + CameraCenter.Y), Math.Abs((e.X + CameraCenter.X) - initialX), Math.Abs((e.Y + CameraCenter.Y) - initialY));

                    if (FrameListBox.SelectedIndex == -1)
                    {
                        FrameRectXUpDown.Value = FrameRect.X;
                        FrameRectYUpDown.Value = FrameRect.Y;
                        FrameRectWidthUpDown.Value = FrameRect.Width;
                        FrameRectHeightUpDown.Value = FrameRect.Height;
                    }
                    this.Invalidate();
                }
                else if (DrawingCollisionRect)
                {
                    int width = e.X - initialX, height = e.Y - initialY;
                    CollisionRect = new Rectangle(Math.Min(initialX, e.X + CameraCenter.X), Math.Min(initialY, e.Y + CameraCenter.Y), Math.Abs((e.X + CameraCenter.X) - initialX), Math.Abs((e.Y + CameraCenter.Y) - initialY));
                    CollisionRectXUpDown.Value = CollisionRect.X;
                    CollisionRectYUpDown.Value = CollisionRect.Y;
                    CollisionRectWidthUpDown.Value = CollisionRect.Width;
                    CollisionRectHeightUpDown.Value = CollisionRect.Height;
                    this.Invalidate();
                }
            }
        }

        private void SpritePanel_MouseUp(object sender, MouseEventArgs e)
        {
            isDown = false;
        }

        #endregion

        #region Buttons
        private void FrameRectButton_Click(object sender, EventArgs e)
        {
            CollisionRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = SystemColors.Control;
            FrameRectButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = true;
            DrawingCollisionRect = false;
            DrawingAnchorPoint = false;
            DrawingParticlePt = false;
            isPaused = true;
            FrameListBox.SelectedIndex = -1;
        }

        private void AnchorButton_Click(object sender, EventArgs e)
        {
            FrameListBox.SelectedIndex = -1;
            FrameRectButton.BackColor = SystemColors.Control;
            CollisionRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = false;
            DrawingAnchorPoint = true;
            DrawingCollisionRect = false;
            DrawingParticlePt = false;
            isPaused = true;
        }

        private void CollisionRectButton_Click(object sender, EventArgs e)
        {
            FrameListBox.SelectedIndex = -1;
            FrameRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = SystemColors.Control;
            CollisionRectButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = false;
            DrawingCollisionRect = true;
            DrawingAnchorPoint = false;
            DrawingParticlePt = false;
            isPaused = true;
        }
        private void ParticlePtButton_Click(object sender, EventArgs e)
        {
            FrameListBox.SelectedIndex = -1;
            FrameRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = SystemColors.Control;
            CollisionRectButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = false;
            DrawingCollisionRect = false;
            DrawingAnchorPoint = false;
            DrawingParticlePt = true;
            isPaused = true;
        }

        private void AddFrameButton_Click(object sender, EventArgs e)
        {
            if (FrameRect != Rectangle.Empty && CollisionRect != Rectangle.Empty && AnchorPt != Rectangle.Empty && ParticlePt != Rectangle.Empty)
            {
                Frames frame = new Frames();
                frame.Framerect = FrameRect;
                frame.Collisionrect = CollisionRect;
                frame.Anchorpt = AnchorPt;
                frame.particlept = ParticlePt;
                int count = FrameListBox.Items.Count + 1;
                frame.name = "Frame " + count.ToString();
                FrameListBox.Items.Add(frame);

                FrameRect = Rectangle.Empty;
                CollisionRect = Rectangle.Empty;
                AnchorPt = Rectangle.Empty;
                ParticlePt = Rectangle.Empty;
                AnchorXUpDown.Value = 0;
                AnchorYUpDown.Value = 0;
                FrameRectXUpDown.Value = 0;
                FrameRectYUpDown.Value = 0;
                FrameRectWidthUpDown.Value = 0;
                FrameRectHeightUpDown.Value = 0;
                CollisionRectXUpDown.Value = 0;
                CollisionRectYUpDown.Value = 0;
                CollisionRectWidthUpDown.Value = 0;
                CollisionRectHeightUpDown.Value = 0;
                ParticlePtXUpDown.Value = 0;
                ParticlePtYUpDown.Value = 0;


                FrameRectButton.BackColor = SystemColors.Control;
                AnchorButton.BackColor = SystemColors.Control;
                CollisionRectButton.BackColor = SystemColors.Control;
                //FrameListBox.SelectedIndex = 0;
            }
        }

        private void RemoveFrameButton_Click(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex >= 0)
            {
                FrameListBox.Items.RemoveAt(FrameListBox.SelectedIndex);
            }
            FrameListBox.SelectedIndex = -1;
            AnchorXUpDown.Value = AnchorPt.X;
            AnchorYUpDown.Value = AnchorPt.Y;
            FrameRectXUpDown.Value = FrameRect.X;
            FrameRectYUpDown.Value = FrameRect.Y;
            FrameRectWidthUpDown.Value = FrameRect.Width;
            FrameRectHeightUpDown.Value = FrameRect.Height;
            CollisionRectXUpDown.Value = CollisionRect.X;
            CollisionRectYUpDown.Value = CollisionRect.Y;
            CollisionRectWidthUpDown.Value = CollisionRect.Width;
            CollisionRectHeightUpDown.Value = CollisionRect.Height;
            ParticlePtXUpDown.Value = ParticlePt.X;
            ParticlePtYUpDown.Value = ParticlePt.Y;
        }

        private void PlayButton_Click(object sender, EventArgs e)
        {
            if (isPaused == true)
            {
                isPaused = false;
                DrawingFrameRect = DrawingCollisionRect = DrawingAnchorPoint = false;
            }

        }

        private void PauseButton_Click(object sender, EventArgs e)
        {
            if (isPaused == false)
            {
                isPaused = true;
            }
        }

        private void NextFrameButton_Click(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex < FrameListBox.Items.Count - 1 && FrameListBox.SelectedIndex != -1)
            {
                FrameListBox.SelectedIndex++;
            }
            else
                FrameListBox.SelectedIndex = 0;
        }

        private void PreviousFrameButton_Click(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex == 0)
            {
                FrameListBox.SelectedIndex = FrameListBox.Items.Count - 1;
            }
            else
            {
                FrameListBox.SelectedIndex--;
            }
        }

        private void RemoveButton_Click(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                FrameListBox.Items.RemoveAt(FrameListBox.SelectedIndex);
                FrameListBox.SelectedIndex = -1;
                AnchorPt = Rectangle.Empty;
                FrameRect = Rectangle.Empty;
                CollisionRect = Rectangle.Empty;
            }
        }

        private void DeselectButton_Click(object sender, EventArgs e)
        {
            FrameListBox.SelectedIndex = -1;
            AnchorXUpDown.Value = AnchorPt.X;
            AnchorYUpDown.Value = AnchorPt.Y;
            FrameRectXUpDown.Value = FrameRect.X;
            FrameRectYUpDown.Value = FrameRect.Y;
            FrameRectWidthUpDown.Value = FrameRect.Width;
            FrameRectHeightUpDown.Value = FrameRect.Height;
            CollisionRectXUpDown.Value = CollisionRect.X;
            CollisionRectYUpDown.Value = CollisionRect.Y;
            CollisionRectWidthUpDown.Value = CollisionRect.Width;
            CollisionRectHeightUpDown.Value = CollisionRect.Height;
        }

        private void AddAnimationButton_Click(object sender, EventArgs e)
        {

        }

        private void RemoveAnimButton_Click(object sender, EventArgs e)
        {

        }

        #endregion

        #region UpDownChanges
        private void FrameRectXUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.framerect.X = (int)FrameRectXUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                FrameRect.X = (int)FrameRectXUpDown.Value;
        }

        private void FrameRectYUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.framerect.Y = (int)FrameRectYUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                FrameRect.Y = (int)FrameRectYUpDown.Value;
        }

        private void FrameRectWidthUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.framerect.Width = (int)FrameRectWidthUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                FrameRect.Width = (int)FrameRectWidthUpDown.Value;
        }

        private void FrameRectHeightUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.framerect.Height = (int)FrameRectHeightUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                FrameRect.Height = (int)FrameRectHeightUpDown.Value;
        }

        private void CollisionRectXUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.collisionrect.X = (int)CollisionRectXUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                CollisionRect.X = (int)CollisionRectXUpDown.Value;
        }

        private void CollisionRectYUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.collisionrect.Y = (int)CollisionRectYUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                CollisionRect.Y = (int)CollisionRectYUpDown.Value;
        }

        private void CollisionRectWidthUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.collisionrect.Width = (int)CollisionRectWidthUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                CollisionRect.Width = (int)CollisionRectWidthUpDown.Value;
        }

        private void CollisionRectHeightUpDown_ValueChanged(object sender, EventArgs e)
        {

            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.collisionrect.Height = (int)CollisionRectHeightUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                CollisionRect.Height = (int)CollisionRectHeightUpDown.Value;
        }

        private void AnchorXUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.anchorpt.X = (int)AnchorXUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                AnchorPt.X = (int)AnchorXUpDown.Value;
        }

        private void AnchorYUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.anchorpt.Y = (int)AnchorYUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                AnchorPt.Y = (int)AnchorYUpDown.Value;
        }

        private void AnimationSpeedUpDown_ValueChanged(object sender, EventArgs e)
        {

        }

        private void FrameDurationUpDown_ValueChanged(object sender, EventArgs e)
        {
            animationtime = (float)FrameDurationUpDown.Value;
        }

        private void ParticlePtXUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.particlept.X = (int)ParticlePtXUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                ParticlePt.X = (int)ParticlePtXUpDown.Value;
        }

        private void ParticlePtYUpDown_ValueChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames frametemp = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                frametemp.particlept.Y = (int)ParticlePtYUpDown.Value;
                FrameListBox.Items[FrameListBox.SelectedIndex] = frametemp;
            }
            else if (FrameListBox.SelectedIndex == -1)
                ParticlePt.Y = (int)ParticlePtYUpDown.Value;

        }



        #endregion

        private void FrameListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex != -1)
            {
                Frames tframe = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                AnchorXUpDown.Value = tframe.anchorpt.X;
                AnchorYUpDown.Value = tframe.anchorpt.Y;
                ParticlePtXUpDown.Value = tframe.particlept.X;
                ParticlePtYUpDown.Value = tframe.particlept.Y;
                CollisionRectXUpDown.Value = tframe.collisionrect.X;
                CollisionRectYUpDown.Value = tframe.collisionrect.Y;
                CollisionRectWidthUpDown.Value = tframe.collisionrect.Width;
                CollisionRectHeightUpDown.Value = tframe.collisionrect.Height;
                FrameRectXUpDown.Value = tframe.framerect.X;
                FrameRectYUpDown.Value = tframe.framerect.Y;
                FrameRectWidthUpDown.Value = tframe.framerect.Width;
                FrameRectHeightUpDown.Value = tframe.framerect.Height;
            }
        }
        private void LoopingCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (LoopingCheckBox.Checked)
                FrameLoop = true;
            else
                FrameLoop = false;
        }
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
            isLooping = false;
        }
        private void LoadSpriteSheet_Click(object sender, EventArgs e)
        {
            OpenFileDialog Load = new OpenFileDialog();
            if (DialogResult.OK == Load.ShowDialog())
            {
                spritesheetimg = TextureManager.LoadTexture(Load.FileName);
                spritesize = new Size(TextureManager.GetTextureWidth(spritesheetimg), TextureManager.GetTextureHeight(spritesheetimg));

                UpdateScrollBars();
            }
        }
        private void UpdateScrollBars()
        {
            SpritePanelHScrollBar.Minimum = 0;
            SpritePanelVScrollBar.Minimum = 0;
            SpritePanelHScrollBar.Maximum = spritesize.Width;
            SpritePanelVScrollBar.Maximum = spritesize.Height;
            SpritePanelHScrollBar.Visible = SpritePanelHScrollBar.Maximum > 0;
            SpritePanelVScrollBar.Visible = SpritePanelVScrollBar.Maximum > 0;
            AnimationPanelVScrollBar.Minimum = 0;
            AnimationPanelHScrollBar.Minimum = 0;

            if (FrameListBox.SelectedIndex != -1)
            {
                Frames tf = (Frames)FrameListBox.Items[FrameListBox.SelectedIndex];
                AnimationPanelVScrollBar.Maximum = tf.framerect.Bottom;
                AnimationPanelHScrollBar.Maximum = tf.Framerect.Width;
            }
            else
            {
                AnimationPanelVScrollBar.Maximum = 0;
                AnimationPanelHScrollBar.Maximum = 0;
            }
            AnimationPanelVScrollBar.Visible = AnimationPanelVScrollBar.Maximum > 0;
            AnimationPanelHScrollBar.Visible = AnimationPanelHScrollBar.Maximum > 0;

        }
        private void SpritePanelVScrollBar_ValueChanged(object sender, EventArgs e)
        {
            if (SpritePanelVScrollBar.Visible == false)
                return;
            CameraCenter.Y = SpritePanelVScrollBar.Value;
            this.Invalidate();
        }
        private void SpritePanelHScrollBar_ValueChanged(object sender, EventArgs e)
        {
            if (SpritePanelHScrollBar.Visible == false)
                return;
            CameraCenter.X = SpritePanelHScrollBar.Value;
            this.Invalidate();
        }
        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (spritesheetimg != -1)
                TextureManager.UnloadTexture(spritesheetimg);
            AnchorXUpDown.Value = 0;
            AnchorYUpDown.Value = 0;
            FrameRectXUpDown.Value = 0;
            FrameRectYUpDown.Value = 0;
            FrameRectWidthUpDown.Value = 0;
            FrameRectHeightUpDown.Value = 0;
            CollisionRectXUpDown.Value = 0;
            CollisionRectYUpDown.Value = 0;
            CollisionRectHeightUpDown.Value = 0;
            CollisionRectWidthUpDown.Value = 0;
            FrameListBox.SelectedIndex = -1;
            FrameListBox.Items.Clear();
            FrameRect = Rectangle.Empty;
            CollisionRect = Rectangle.Empty;
            AnchorPt = Rectangle.Empty;
            AnimationNameTextBox.Clear();
            AnimationSpeedUpDown.Value = 0;
            FrameDurationUpDown.Value = 0;
            //TriggerTypeComboBox.SelectedIndex = 0;
            TriggerNameBox.Clear();
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (!isPaused)
                Timer += 0.100f;
        }

        private void AnimationPanelVScrollBar_ValueChanged(object sender, EventArgs e)
        {
            if (AnimationPanelVScrollBar.Visible == false)
            {
                return;
            }
        }


        private void fileToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void AnimationPanelHScrollBar_ValueChanged(object sender, EventArgs e)
        {
            if (AnimationPanelHScrollBar.Visible == false)
            {
                return;
            }
        }

        

    }
}
