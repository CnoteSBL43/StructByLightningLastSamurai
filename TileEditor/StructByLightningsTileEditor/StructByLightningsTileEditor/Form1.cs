using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace StructByLightningsTileEditor
{
    public partial class Form1 : Form
    {


        // Setting Up the SGP DIRECTX Draw Variable And it is going to Equal Null And Be Initalized In The 
        // Function called Iniilize;
        SGP.CSGP_Direct3D m_DirectXDraw = null;


        // Setting Up the SGP Texture Mangager so that The User can Get bitamps for Pngs to the Screen so they Can have there own Custom TIles 
        SGP.CSGP_TextureManager m_Texture = null;


        // Seting Up the Grid Size by making a Size Variable and Setting IT to 10 by 10 By Defualt
        Size m_GridSize = new Size(10, 10);


        Size m_Picture = new Size(10, 10);
        // Setting UP the Pixal Size by making a Size Variabl and Settin it to 32 by 32 by defualt;
        Size m_PixalSize = new Size(32, 32);

        Size m_PixalTileSize = new Size(16, 16);
        // IsSelected is a Bollian that is ued o Select a tile and which one you want to use to make it on the Grid
        bool IsSelected = false;

        // What this does is a List of Collison Rectangles so that I can Save them
        // When the time comes i can Idplay all of them on the screen and then Save them all in XML document 
        List<Rectangle> CollisionRectangles = new List<Rectangle>();
        List<Rectangle> RespawnRectangles = new List<Rectangle>();
        List<Rectangle> CheckPointRectangle = new List<Rectangle>();
        List<Rectangle> AIRectangles = new List<Rectangle>();
        List<TIleClass> Tiles = new List<TIleClass>();
        // This is a TileClass Variable that is used to stroe the current tile you Choose so that you can Place it on the Grid
        TIleClass CurrentSelectedTile;

        // This a Tile CLass Array that is going to be used to make sure in the grid you are placing the right tiles in them. 
        TIleClass[,] TileMap = new TIleClass[10, 10];


        // This a Rectangle Storeing The Collison Rctangles.
        Rectangle CollisonRect;

        // This is an Interger for The TileImage so that it can have an id in the Texture Manager
        int TileImage = -1;

        public Form1()
        {
            InitializeComponent();
            this.Focus();
             GridPanel.AutoScroll = true;
            this.DoubleBuffered = true;
            GridPanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalSize.Width,m_Picture.Height * m_PixalSize.Height);
             TilePanel.AutoScrollMinSize = TilePanel.Size;
             TilePanel.AutoScroll = true;

        }
        // This is a Public Bool Function IsLooping. What this will do is set the and get the boolean 
        // So that Islooping can make the Game Run Untill Someone Quits The Editor
        public bool IsLooping
        {
            // This is a C# Acseseser for IsLooping
            get;
            //  this is a C# Mutator for IsLooping
            set;
        }

        // This is a Public Void function Initialize. What this will do will set all of are variables up at the start of our program so that we can use them
        public void Initialize()
        {
            // IsLooping Is Set to True in Initialize so that the program will Run untill IsLooping Is Set to False which
            // Will happen thwn they exit the Editor
            IsLooping = true;

            // Setting up the SGP Wrappers By Inilizing m_DirectXDraw & m_Texture
            m_DirectXDraw = SGP.CSGP_Direct3D.GetInstance();
            m_Texture = SGP.CSGP_TextureManager.GetInstance();

            // m_DirectXDraw is now going to Initalize Panel 1 to Render the Grid
            m_DirectXDraw.Initialize(GridPanel, false);
            m_Texture.Initialize(m_DirectXDraw.Device, m_DirectXDraw.Sprite);
            // Going to add a DirectX AddRenderTarget so I know where its gonna Render It will Render in GridPanel
            m_DirectXDraw.AddRenderTarget(GridPanel);


            m_DirectXDraw.Initialize(TilePanel, false);
            m_DirectXDraw.AddRenderTarget(TilePanel);


            // Setting the Gridsize to the Numeric UPDown WIdth and Height
            GridWidth.Value = m_Picture.Width;
            GridHeight.Value = m_Picture.Height;

            // Seting the PixalSize to the Numeric UpDown Width and Height
            PixalWidth.Value = m_PixalSize.Width;
            PixalHeight.Value = m_PixalSize.Height;

        }

        // This is A Public Void fuction Called Terminate. What this will do is destroy everything you have at the end of your Program
        // So that you will not have any memeory leaks or crashes 
        public void Terminate()
        {


        }


        // This is A Public Void Fuction Called Render. What this will do Is Render everything on Panel 1 And Panel 2 In Real Time
        public void Render()
        {

            GridPanelRender();
            if (TileImage != -1)
            {
                TilePanelRender();
            }

        }

        public void GridPanelRender()
        {
            m_DirectXDraw.Resize(GridPanel, GridPanel.ClientRectangle.Width, GridPanel.ClientRectangle.Height, true);
            // What this is doing is Clearin the screen Eachtime and Making the Screen Black
            m_DirectXDraw.Clear(GridPanel, Color.FromArgb(255, 0, 0, 0));
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.DeviceBegin();
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.SpriteBegin();
            {
                Point OffsetScroll = new Point(0, 0);
                OffsetScroll.X += GridPanel.AutoScrollPosition.X;
                OffsetScroll.Y += GridPanel.AutoScrollPosition.Y;
                //This Nested For loop is for Rendering the Grid to the GridPanel/
                // You are going to Draw a Row of Ten Rectangles ten times by defualt can Changed inside Editor
                for (int X = 0; X < m_Picture.Width; X++)
                {
                    for (int Y = 0; Y < m_Picture.Height; Y++)
                    {
                        // This is your DestinationRectangle That you will use to Render to the Screen
                        Rectangle DestinationRectangle = Rectangle.Empty;
                        // you are going to Multiply to get the Width of the Pixal size inside of the rectangle
                        DestinationRectangle.X = (X * m_PixalSize.Width) + OffsetScroll.X ;
                        // you are going to Multiply to get the Height of the Pixal size inside of the rectangle
                        DestinationRectangle.Y = (Y * m_PixalSize.Height) + OffsetScroll.Y;
                        // you are going to Set the whole m_Pixalsize to the whole rectangle
                        DestinationRectangle.Size = m_PixalSize;
                       // DestinationRectangle.Offset(GridPanel.AutoScrollPosition);
                        if (TileMap[X, Y] != null)
                        {
                            Rectangle SourceRectangle = Rectangle.Empty;
                            SourceRectangle.X = TileMap[X, Y].PositionX * m_PixalSize.Width;
                            SourceRectangle.Y = TileMap[X, Y].PositionY * m_PixalSize.Height;
                            SourceRectangle.Size = m_PixalSize;
                            m_Texture.Draw(TileImage, DestinationRectangle.X, DestinationRectangle.Y, 1, 1, SourceRectangle);



                        }
                        m_DirectXDraw.DrawHollowRect(DestinationRectangle, Color.BlueViolet, 1);


                        #region Collision Rectangle ForLoop

                        if (CollisionRectangles != null)
                        {


                            for (int i = 0; i < CollisionRectangles.Count; i++)
                            {
                                Rectangle Collison = Rectangle.Empty;
                                Collison.X = (CollisionRectangles[i].X * m_PixalSize.Width) + OffsetScroll.X; 
                                Collison.Y = (CollisionRectangles[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("C", Collison.X, Collison.Y, Color.Blue);
                            }
                        }


                        #endregion




                        #region Respawn Rectangle For Loop

                        if (RespawnRectangles != null)
                        {


                            for (int i = 0; i < RespawnRectangles.Count; i++)
                            {
                                Rectangle Collison = Rectangle.Empty;
                                Collison.X = RespawnRectangles[i].X * m_PixalSize.Width;
                                Collison.Y = RespawnRectangles[i].Y * m_PixalSize.Height;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("R", Collison.X, Collison.Y, Color.Orange);
                            }
                        }





                        #endregion



                        #region CheckPoint Rectangle ForLoop

                        if (CheckPointRectangle != null)
                        {


                            for (int i = 0; i < CheckPointRectangle.Count; i++)
                            {
                                Rectangle Collison = Rectangle.Empty;
                                Collison.X = CheckPointRectangle[i].X * m_PixalSize.Width;
                                Collison.Y = CheckPointRectangle[i].Y * m_PixalSize.Height;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("CP", Collison.X, Collison.Y, Color.Green);
                            }
                        }


                        #endregion



                    }




                }






            }
            m_DirectXDraw.SpriteEnd();
            m_DirectXDraw.DeviceEnd();

            m_DirectXDraw.Present();

        }

        public void TilePanelRender()
        {

            Color NewColor;
            // What this is doing is Clearin the screen Eachtime and Making the Screen Black
            m_DirectXDraw.Clear(TilePanel, Color.FromArgb(255, 0, 0, 0));
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.DeviceBegin();
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.SpriteBegin();
            {
                Point offset = new Point(0, 0);
                offset.X += TilePanel.AutoScrollPosition.X;
                offset.Y += TilePanel.AutoScrollPosition.Y;
                m_Texture.Draw(TileImage, offset.X, offset.Y);
                for (int X = 0; X < m_Picture.Width; X++)
                {
                    for (int Y = 0; Y < m_Picture.Height; Y++)
                    {
                        // This is your DestinationRectangle That you will use to Render to the Screen
                        Rectangle DestinationRectangle = Rectangle.Empty;
                        // you are going to Multiply to get the Width of the Pixal size inside of the rectangle
                        DestinationRectangle.X = X * m_PixalSize.Width;
                        // you are going to Multiply to get the Height of the Pixal size inside of the rectangle
                        DestinationRectangle.Y = Y * m_PixalSize.Height;
                        // you are going to Set the whole m_Pixalsize to the whole rectangle
                        DestinationRectangle.Size = m_PixalSize;

                        // You are going to Draw a Row of Ten Rectangles ten times by defualt can Changed inside Editor
                        m_DirectXDraw.DrawHollowRect(DestinationRectangle, Color.AntiqueWhite, 1);
                        if (IsSelected)
                        {
                            NewColor = System.Drawing.Color.Yellow;
                        }
                        else
                        {
                            NewColor = System.Drawing.Color.Black;
                        }
                        if (CurrentSelectedTile != null)
                        {
                            m_DirectXDraw.DrawHollowRect(new Rectangle(CurrentSelectedTile.PositionX * m_PixalSize.Width, CurrentSelectedTile.PositionY * m_PixalSize.Height, m_PixalSize.Width, m_PixalSize.Height), NewColor, 2);
                        }

                    }
                }

            }

            m_DirectXDraw.SpriteEnd();
            m_DirectXDraw.DeviceEnd();

            m_DirectXDraw.Present();

        }


        //  This is a NumericUpdown Button Function And it is Dealing With the GridWidth of the Tile Grid
        private void GridWidth_ValueChanged(object sender, EventArgs e)
        {
            // Setting the NumericUpDown Values to the the Grid Size Width
            #region This is code to rezie the Grid and Keep The tile Still in Place
            Size Temp = m_Picture;
            if (Temp.Height > m_Picture.Height)
                Temp.Height = m_Picture.Height;
            if (Temp.Width > m_Picture.Width)
                Temp.Width = m_Picture.Width;
            TIleClass[,] tileMapTemp = new TIleClass[m_Picture.Width, m_Picture.Height];
            for (int X = 0; X < m_Picture.Width; X++)
            {
                for (int Y = 0; Y < m_Picture.Height; Y++)
                {
                    tileMapTemp[X, Y] = TileMap[X, Y];
                }

            }

            // Setting the NumericUpDown Values to the the Grid Size Height
            m_Picture.Width = (int)GridWidth.Value;

            TileMap = new TIleClass[(int)m_Picture.Width, (int)m_Picture.Height];
            if (Temp.Width < m_Picture.Width)
            {
                for (int X = 0; X < Temp.Width; X++)
                {
                    for (int Y = 0; Y < Temp.Height; Y++)
                    {
                        TileMap[X, Y] = tileMapTemp[X, Y];
                    }

                }
            }
            else if (Temp.Width > m_Picture.Width)
            {
                for (int X = 0; X < m_Picture.Width; X++)
                {
                    for (int Y = 0; Y < m_Picture.Height; Y++)
                    {
                        TileMap[X, Y] = tileMapTemp[X, Y];
                    }

                }
            }
            GridPanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalSize.Width, m_Picture.Height * m_PixalSize.Height);
            #endregion
        }

        //  This is a NumericUpdown Button Function And it is Dealing With the GridHeight of the Tile Grid
        private void GridHeight_ValueChanged(object sender, EventArgs e)
        {
            Size Temp = m_Picture;
            if (Temp.Width > m_Picture.Width)
                Temp.Width = m_Picture.Width;
            if (Temp.Height > m_Picture.Height)
                Temp.Height = m_Picture.Height;
            TIleClass[,] tileMapTemp = new TIleClass[m_Picture.Width, m_Picture.Height];
            for (int X = 0; X < m_Picture.Width; X++)
            {
                for (int Y = 0; Y < m_Picture.Height; Y++)
                {
                    tileMapTemp[X, Y] = TileMap[X, Y];
                }
             
            }

            // Setting the NumericUpDown Values to the the Grid Size Height
            m_Picture.Height = (int)GridHeight.Value; 
            
            TileMap = new TIleClass[(int)m_Picture.Width, (int)m_Picture.Height];
          if(Temp.Height<m_Picture.Height)
          {
           for (int X = 0; X < Temp.Width; X++)
            {
                for (int Y = 0; Y < Temp.Height; Y++)
                {
                    TileMap[X, Y] = tileMapTemp[X, Y];
                }

            }
          }
            else if(Temp.Height>m_Picture.Height)
          {
              for (int X = 0; X < m_Picture.Width; X++)
              {
                  for (int Y = 0; Y < m_Picture.Height; Y++)
                  {
                      TileMap[X, Y] = tileMapTemp[X, Y];
                  }

              }
            }
          GridPanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalSize.Width, m_Picture.Height * m_PixalSize.Height);
        }

        //  This is a NumericUpdown Button Function And it is Dealing With the PixalWidth of the Pixal size of the Tiles
        private void PixalWidth_ValueChanged(object sender, EventArgs e)
        {
            // Setting the NumericUpDown Values to the the Pixal Size Width
            m_PixalSize.Width = (int)PixalWidth.Value;
            GridPanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalSize.Width, m_Picture.Height * m_PixalSize.Height);
        }

        //  This is a NumericUpdown Button Function And it is Dealing With the PixalHeight of the Pixal size of the Tiles
        private void PixalHeight_ValueChanged(object sender, EventArgs e)
        {
            // Setting the NumericUpDown Values to the the Pixal Size Height
            m_PixalSize.Height = (int)PixalHeight.Value;
            GridPanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalSize.Width, m_Picture.Height * m_PixalSize.Height);
            this.Invalidate();

        }

        // This Is the Closing Function that makes the Whole Editor Close when You Exit it
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // Setting IsLooping to False When The User Clickes the BIg Red X Button
            IsLooping = false;
        }

        private void loadTileSetToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog Load = new OpenFileDialog();
            // Load.Filter = "All Files(*.*)|*.*|My Files(*.myf)|*.myf";
            if (DialogResult.OK == Load.ShowDialog())
            {

                TileImage = m_Texture.LoadTexture(Load.FileName);

            }

        }

        private void TilePanel_MouseClick(object sender, MouseEventArgs e)
        {

            if (TileImage != -1)
            {
                CurrentSelectedTile = new TIleClass(e.Location.X / m_PixalSize.Width, e.Location.Y / m_PixalSize.Height);

                IsSelected = true;
            }

        }

        private void GridPanel_MouseClick(object sender, MouseEventArgs e)
        {
            #region this is a Check for the Left Mosue CLick so that you can Grab a Tile
            if (e.Button == MouseButtons.Left)
            {
                int X = (e.Location.X + GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y + GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;
                if (X >= m_Picture.Width || Y >= m_Picture.Height || X < 0 || Y < 0)
                {
                    return;
                }
                TileMap[X, Y] = CurrentSelectedTile;
                this.Invalidate();
            }
            #endregion


            #region This is a Check for the Right mous click and Radiobutton Collison

            if (e.Button == MouseButtons.Right && CollisionRectangleButton.Checked == true)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;
                CollisonRect = new Rectangle(X, Y, 32, 32);
                CollisionRectangles.Add(CollisonRect);

            }

            #endregion


            #region this is a Check for the Right mouse Click and Radio Button Respawn
            if (e.Button == MouseButtons.Right && RespawnRectangleButton.Checked == true)
            {
                int X = e.Location.X / m_PixalSize.Width;
                int Y = e.Location.Y / m_PixalSize.Height;

                CollisonRect = new Rectangle(X, Y, 32, 32);
                RespawnRectangles.Add(CollisonRect);

            }
            #endregion


            #region This is a Check for the Right Mouse Click and Radio Button Respawn
            if (e.Button == MouseButtons.Right && CheckPointRectangleButton.Checked == true)
            {
                int X = e.Location.X / m_PixalSize.Width;
                int Y = e.Location.Y / m_PixalSize.Height;

                CollisonRect = new Rectangle(X, Y, 32, 32);
                CheckPointRectangle.Add(CollisonRect);

            }
            #endregion


            #region This is a Check for the Right Mouse Click and Radio Button Respawn

            if (e.Button == MouseButtons.Right && RespawnRectangleButton.Checked == true)
            {
                int X = e.Location.X / m_PixalSize.Width;
                int Y = e.Location.Y / m_PixalSize.Height;

                CollisonRect = new Rectangle(X, Y, 32, 32);

                AIRectangles.Add(CollisonRect);

            }
            #endregion

            this.Invalidate();
        }

        private void GridPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y ) / m_PixalSize.Height;
                if (X >= m_Picture.Width || Y >= m_Picture.Height || Y < 0)
                {
                    return;
                }
                TileMap[X, Y] = CurrentSelectedTile;
                // Tiles.Add(TileMap[X, Y]);
                this.Invalidate();
                // ScrollBarRenderer Render = new ScrollBarRenderer


            }
        }

        private void GridPanel_Scroll(object sender, ScrollEventArgs e)
        {



        }


    }
}
