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
        public bool isLooping;
        int spritesheetimg = -1;
        bool isDown = false, DrawingFrameRect = false, DrawingCollisionRect = false, DrawingAnchorPoint = false;
        int initialX, initialY;
        Rectangle FrameRect = Rectangle.Empty;
        Rectangle CollisionRect = Rectangle.Empty;
        public Rectangle AnchorPt = new Rectangle(0, 0, 0, 0);
        int FRed = 0, FGreen = 0, FBlue = 255;
        int CRed = 255, CGreen = 0, CBlue = 0;
        int ARed = 0, AGreen = 0, ABlue = 0;
        Size spritesize = Size.Empty;
        Size Camera = Size.Empty;
        Point CameraCenter = Point.Empty;

        public bool IsLooping
        {
            get { return isLooping; }
            set { isLooping = value; }
        }

        SGP.CSGP_Direct3D DXDraw = null;
        SGP.CSGP_TextureManager TextureManager;


        public Form1()
        {
            InitializeComponent();
            this.Focus();
            this.DoubleBuffered = true;
            UpdateScrollBars();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }



        public void Initialize()
        {
            DXDraw = SGP.CSGP_Direct3D.GetInstance();
            TextureManager = SGP.CSGP_TextureManager.GetInstance();
            DXDraw.Initialize(SpritePanel, false);
            //DXDraw.Initialize(AnimationPanel, false);
            DXDraw.AddRenderTarget(SpritePanel);
            //DXDraw.AddRenderTarget(AnimationPanel);
            TextureManager.Initialize(DXDraw.Device, DXDraw.Sprite);
            isLooping = true;
            FrameListBox.SelectedIndex = -1;
            Camera = SpritePanel.Size;
            CameraCenter = new Point(0, 0);
        }

        public void update()
        {
            UpdateScrollBars();
        }
        public void RenderTop()
        {
            DXDraw.Clear(SpritePanel, Color.FromArgb(255, 255, 255, 255));
            DXDraw.DeviceBegin();
            DXDraw.SpriteBegin();
            {
                if (spritesheetimg != -1)
                    TextureManager.Draw(spritesheetimg, 0 - CameraCenter.X, 0 - CameraCenter.Y);//CameraCenter.X, CameraCenter.Y);
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

                }
            }
            DXDraw.SpriteEnd();
            DXDraw.DeviceEnd();
            DXDraw.Present();
        }

        public void RenderBottom()
        {

        }
        public void Render()
        {
            RenderTop();
        }

        public void Terminate()
        {

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            isLooping = false;
        }

        private void SpritePanel_MouseDown(object sender, MouseEventArgs e)
        {

            isDown = true;
            initialX = e.Location.X + CameraCenter.X;
            initialY = e.Location.Y + CameraCenter.Y;
            if (!DrawingFrameRect && !DrawingCollisionRect && DrawingAnchorPoint)
            {
                AnchorPt = new Rectangle(e.X - CameraCenter.X, e.Y - CameraCenter.Y, 1, 1);
                AnchorXUpDown.Value = initialX;
                AnchorYUpDown.Value = initialY;
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


                    FrameRectXUpDown.Value = FrameRect.X;
                    FrameRectYUpDown.Value = FrameRect.Y;
                    FrameRectWidthUpDown.Value = FrameRect.Width;
                    FrameRectHeightUpDown.Value = FrameRect.Height;
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

        private void FrameRectButton_Click(object sender, EventArgs e)
        {
            CollisionRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = SystemColors.Control;
            FrameRectButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = true;
            DrawingCollisionRect = false;
            DrawingAnchorPoint = false;
        }

        private void AnchorButton_Click(object sender, EventArgs e)
        {
            FrameRectButton.BackColor = SystemColors.Control;
            CollisionRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = false;
            DrawingAnchorPoint = true;
            DrawingCollisionRect = false;
        }

        private void CollisionRectButton_Click(object sender, EventArgs e)
        {
            FrameRectButton.BackColor = SystemColors.Control;
            AnchorButton.BackColor = SystemColors.Control;
            CollisionRectButton.BackColor = Color.FromArgb(255, 255, 255, 255);
            DrawingFrameRect = false;
            DrawingCollisionRect = true;
            DrawingAnchorPoint = false;
        }

        private void AddFrameButton_Click(object sender, EventArgs e)
        {
            if (FrameRect != Rectangle.Empty && CollisionRect != Rectangle.Empty && AnchorPt != Rectangle.Empty)
            {
                Frames frame = new Frames();
                frame.Framerect = FrameRect;
                frame.Collisionrect = CollisionRect;
                frame.Anchorpt = AnchorPt;
                int count = FrameListBox.Items.Count + 1;
                frame.name = "Frame " + count.ToString();
                FrameListBox.Items.Add(frame);

                FrameRect = Rectangle.Empty;
                CollisionRect = Rectangle.Empty;
                AnchorPt = Rectangle.Empty;
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

                FrameRectButton.BackColor = SystemColors.Control;
                AnchorButton.BackColor = SystemColors.Control;
                CollisionRectButton.BackColor = SystemColors.Control;
                //FrameListBox.Items.
            }
        }

        private void FrameListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void FrameRectXUpDown_ValueChanged(object sender, EventArgs e)
        {
            FrameRect.X = (int)FrameRectXUpDown.Value;
        }

        private void FrameRectYUpDown_ValueChanged(object sender, EventArgs e)
        {
            FrameRect.Y = (int)FrameRectYUpDown.Value;
        }

        private void FrameRectWidthUpDown_ValueChanged(object sender, EventArgs e)
        {
            FrameRect.Width = (int)FrameRectWidthUpDown.Value;
        }

        private void FrameRectHeightUpDown_ValueChanged(object sender, EventArgs e)
        {
            FrameRect.Height = (int)FrameRectHeightUpDown.Value;
        }

        private void CollisionRectXUpDown_ValueChanged(object sender, EventArgs e)
        {
            CollisionRect.X = (int)CollisionRectXUpDown.Value;
        }

        private void CollisionRectYUpDown_ValueChanged(object sender, EventArgs e)
        {
            CollisionRect.Y = (int)CollisionRectYUpDown.Value;
        }

        private void CollisionRectWidthUpDown_ValueChanged(object sender, EventArgs e)
        {
            CollisionRect.Width = (int)CollisionRectWidthUpDown.Value;
        }

        private void CollisionRectHeightUpDown_ValueChanged(object sender, EventArgs e)
        {
            CollisionRect.Height = (int)CollisionRectHeightUpDown.Value;
        }

        private void AnchorXUpDown_ValueChanged(object sender, EventArgs e)
        {
            AnchorPt.X = (int)AnchorXUpDown.Value;
        }

        private void AnchorYUpDown_ValueChanged(object sender, EventArgs e)
        {
            AnchorPt.Y = (int)AnchorYUpDown.Value;
        }

        private void AnimationSpeedUpDown_ValueChanged(object sender, EventArgs e)
        {

        }

        private void FrameDurationUpDown_ValueChanged(object sender, EventArgs e)
        {

        }

        private void RemoveFrameButton_Click(object sender, EventArgs e)
        {
            if (FrameListBox.SelectedIndex >= 0)
            {
                FrameListBox.Items.RemoveAt(FrameListBox.SelectedIndex);
            }
            if (FrameListBox.Items.Count <= 0)
            {
                FrameListBox.SelectedIndex = -1;
            }
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
            if (SpritePanelHScrollBar.Maximum == 0)
            {

            }
            if (SpritePanelVScrollBar.Maximum == 0)
            {

            }
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
    }
}
