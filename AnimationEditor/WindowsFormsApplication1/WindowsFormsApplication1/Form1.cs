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
        Rectangle AnchorPt = Rectangle.Empty;
        int FRed = 0, FGreen = 0, FBlue = 255;
        int CRed = 255, CGreen = 0, CBlue = 0;
        int ARed = 0, AGreen = 0, ABlue = 0;


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

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
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

            spritesheetimg = TextureManager.LoadTexture("../../Megaman.png");

            isLooping = true;


        }

        public void update()
        {

        }
        public void RenderTop()
        {
            DXDraw.Clear(SpritePanel, Color.FromArgb(255, 255, 255, 255));
            DXDraw.DeviceBegin();
            DXDraw.SpriteBegin();
            {
                if (spritesheetimg != -1)
                    TextureManager.Draw(spritesheetimg, 0, 0);

                DXDraw.DrawHollowRect(FrameRect, Color.FromArgb(255, FRed, FGreen, FBlue), 2);
                DXDraw.DrawHollowRect(CollisionRect, Color.FromArgb(255, CRed, CGreen, CBlue), 2);
                DXDraw.DrawHollowRect(AnchorPt, Color.FromArgb(255, ARed, AGreen, ABlue), 2);
                for (int i = 0; i < FrameListBox.Items.Count; i++)
                {
                    Frames temp = (Frames)FrameListBox.Items[i];
                    DXDraw.DrawHollowRect(temp.Framerect, Color.FromArgb(255, FRed, FGreen, FBlue), 2);
                    DXDraw.DrawHollowRect(temp.Collisionrect, Color.FromArgb(255, CRed, CGreen, CBlue), 2);
                    DXDraw.DrawHollowRect(temp.Anchorpt, Color.FromArgb(255, ARed, AGreen, ABlue), 2);
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
            initialX = e.Location.X;
            initialY = e.Location.Y;
            if (!DrawingFrameRect && !DrawingCollisionRect && DrawingAnchorPoint)
            {
                AnchorPt = new Rectangle(e.X, e.Y, 1, 1);
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
                    FrameRect = new Rectangle(Math.Min(initialX, e.X), Math.Min(initialY, e.Y), Math.Abs(e.X - initialX), Math.Abs(e.Y - initialY));
                    FrameRectXUpDown.Value = FrameRect.X;
                    FrameRectYUpDown.Value = FrameRect.Y;
                    FrameRectWidthUpDown.Value = FrameRect.Width;
                    FrameRectHeightUpDown.Value = FrameRect.Height;
                    this.Invalidate();
                }
                else if (DrawingCollisionRect)
                {

                    int width = e.X - initialX, height = e.Y - initialY;
                    CollisionRect = new Rectangle(Math.Min(initialX, e.X), Math.Min(initialY, e.Y), Math.Abs(e.X - initialX), Math.Abs(e.Y - initialY));
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
            DrawingFrameRect = true;
            DrawingCollisionRect = false;
            DrawingAnchorPoint = false;
        }

        private void AnchorButton_Click(object sender, EventArgs e)
        {
            DrawingFrameRect = false;
            DrawingAnchorPoint = true;
            DrawingCollisionRect = false;
        }

        private void CollisionRectButton_Click(object sender, EventArgs e)
        {
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
                frame.name = "Frame " + FrameListBox.Items.Count.ToString();
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
                //FrameListBox.Items.
            }
        }

        private void FrameListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
