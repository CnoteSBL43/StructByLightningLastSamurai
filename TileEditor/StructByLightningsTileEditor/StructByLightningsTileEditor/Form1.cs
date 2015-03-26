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
        //ize m_GridSize = new Size(10, 10);
        Size m_ImageGrid = new Size(10, 10);

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
        string m_filename;

        public Form1()
        {
            InitializeComponent();
            this.Focus();
            GridPanel.AutoScroll = true;
            this.DoubleBuffered = true;
            GridPanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalSize.Width, m_Picture.Height * m_PixalSize.Height);

            //TilePanel.AutoScrollMinSize = new Size(m_Picture.Width * m_PixalTileSize.Width, m_Picture.Height * m_PixalTileSize.Height);
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

            m_DirectXDraw.Initialize(panel1, false);
            m_DirectXDraw.AddRenderTarget(panel1);
            // Setting the Gridsize to the Numeric UPDown WIdth and Height
            GridWidth.Value = m_Picture.Width;
            GridHeight.Value = m_Picture.Height;

            // Seting the PixalSize to the Numeric UpDown Width and Height
            PixalWidth.Value = m_PixalSize.Width;
            PixalHeight.Value = m_PixalSize.Height;
        }

        //    for (int X = 0; X < m_Picture.Width; X++)
        //    {
        //        for (int Y = 0; Y < m_Picture.Height; Y++)
        //        {
        //            CurrentSelectedTile = new TIleClass(0, 32);
        //            TileMap[X, Y] = CurrentSelectedTile;

        //        }
        //    }
        //}


        public void Terminate()
        {


        }


        // This is A Public Void Fuction Called Render. What this will do Is Render everything on Panel 1 And Panel 2 In Real Time
        public void Render()
        {

            GridPanelRender();
            MiniMap();
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
                        DestinationRectangle.X = (X * m_PixalSize.Width) + OffsetScroll.X;
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

                            if (TileMap[X, Y].Collision == 1)
                                m_DirectXDraw.DrawText("C", DestinationRectangle.X, DestinationRectangle.Y, Color.Black);

                            if (TileMap[X, Y].SpawnX != 0 && TileMap[X, Y].SpawnY != 0)
                                m_DirectXDraw.DrawText("R", DestinationRectangle.X, DestinationRectangle.Y, Color.Black);
                        }
                        m_DirectXDraw.DrawHollowRect(DestinationRectangle, Color.BlueViolet, 1);


                        #region Collision Rectangle ForLoop

                        //if (TileMap[X,Y].Collision != null)
                        //{

                        //        Rectangle Collison = Rectangle.Empty;
                        //        Collison.X = (X * m_PixalSize.Width) + OffsetScroll.X;
                        //        Collison.Y = (Y * m_PixalSize.Height) + OffsetScroll.Y;
                        //        Collison.Size = m_PixalSize;

                        //        m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                        //        m_DirectXDraw.DrawText("C", Collison.X, Collison.Y, Color.Blue);

                        //}


                        #endregion




                        #region Respawn Rectangle For Loop

                        if (RespawnRectangles != null)
                        {


                            for (int i = 0; i < RespawnRectangles.Count; i++)
                            {
                                Rectangle Collison = Rectangle.Empty;
                                Collison.X = (RespawnRectangles[i].X * m_PixalSize.Width) + OffsetScroll.X;
                                Collison.Y = (RespawnRectangles[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
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
                                Collison.X = (CheckPointRectangle[i].X * m_PixalSize.Width) + OffsetScroll.X;
                                Collison.Y = (CheckPointRectangle[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("CP", Collison.X, Collison.Y, Color.Green);
                            }
                        }


                        #endregion



                        #region AI Rectangle ForLoop

                        if (AIRectangles != null)
                        {


                            for (int i = 0; i < AIRectangles.Count; i++)
                            {
                                Rectangle Collison = Rectangle.Empty;
                                Collison.X = (AIRectangles[i].X * m_PixalSize.Width) + OffsetScroll.X;
                                Collison.Y = (AIRectangles[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("AI", Collison.X, Collison.Y, Color.Yellow);
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
            m_DirectXDraw.Resize(TilePanel, TilePanel.ClientRectangle.Width, TilePanel.ClientRectangle.Height, true);
            Color NewColor;
            // What this is doing is Clearin the screen Eachtime and Making the Screen Black
            m_DirectXDraw.Clear(TilePanel, Color.FromArgb(255, 0, 0, 0));
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.DeviceBegin();
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.SpriteBegin();
            {
                //size of grid
                int width = m_Texture.GetTextureWidth(TileImage);
                int height = m_Texture.GetTextureHeight(TileImage);
                Size sz = new Size(width / m_PixalSize.Width,
                     height / m_PixalSize.Height);

                Point offset = new Point(0, 0);
                offset.X += TilePanel.AutoScrollPosition.X;
                offset.Y += TilePanel.AutoScrollPosition.Y;
                m_Texture.Draw(TileImage, offset.X, offset.Y);
                for (int X = 0; X < sz.Width; X++)
                {
                    for (int Y = 0; Y < sz.Height; Y++)
                    {
                        // This is your DestinationRectangle That you will use to Render to the Screen
                        Rectangle DestinationRectangle = Rectangle.Empty;
                        // you are going to Multiply to get the Width of the Pixal size inside of the rectangle
                        DestinationRectangle.X = (X * m_PixalSize.Width) + offset.X;
                        // you are going to Multiply to get the Height of the Pixal size inside of the rectangle
                        DestinationRectangle.Y = (Y * m_PixalSize.Height) + offset.Y;
                        // you are going to Set the whole m_Pixalsize to the whole rectangle
                        DestinationRectangle.Size = m_PixalSize;

                        // You are going to Draw a Row of Ten Rectangles ten times by defualt can Changed inside Editor
                        m_DirectXDraw.DrawHollowRect(DestinationRectangle, Color.AntiqueWhite, 1);
                        if (CurrentSelectedTile != null && CurrentSelectedTile.PositionX == X && CurrentSelectedTile.PositionY == Y)
                        {
                            NewColor = System.Drawing.Color.Yellow;
                        }
                        else
                        {
                            NewColor = System.Drawing.Color.Black;

                        }
                        m_DirectXDraw.DrawHollowRect(DestinationRectangle, NewColor, 2);

                        //if (CurrentSelectedTile != null)
                        //{
                        //    
                        //}

                    }
                }

            }

            m_DirectXDraw.SpriteEnd();
            m_DirectXDraw.DeviceEnd();

            m_DirectXDraw.Present();

        }

        public void MiniMap()
        {
            m_DirectXDraw.Resize(GridPanel, panel1.ClientRectangle.Width, panel1.ClientRectangle.Height, true);
            // What this is doing is Clearin the screen Eachtime and Making the Screen Black
            m_DirectXDraw.Clear(panel1, Color.FromArgb(255, 0, 0, 0));
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.DeviceBegin();
            // you are starting to Draw with the Direct X Wrappers
            m_DirectXDraw.SpriteBegin();
            {
                Point OffsetScroll = new Point(0, 0);
                OffsetScroll.X -= panel1.AutoScrollPosition.X;
                OffsetScroll.Y -= panel1.AutoScrollPosition.Y;
                //This Nested For loop is for Rendering the Grid to the GridPanel/
                // You are going to Draw a Row of Ten Rectangles ten times by defualt can Changed inside Editor
                for (int X = 0; X < m_Picture.Width; X++)
                {
                    for (int Y = 0; Y < m_Picture.Height; Y++)
                    {
                        // This is your DestinationRectangle That you will use to Render to the Screen
                        Rectangle DestinationRectangle = Rectangle.Empty;
                        // you are going to Multiply to get the Width of the Pixal size inside of the rectangle
                        DestinationRectangle.X = ((X * m_PixalSize.Width) + OffsetScroll.X);
                        // you are going to Multiply to get the Height of the Pixal size inside of the rectangle
                        DestinationRectangle.Y = ((Y * m_PixalSize.Height) + OffsetScroll.Y);
                        // you are going to Set the whole m_Pixalsize to the whole rectangle


                        //Need to Fix
                        DestinationRectangle.Size = m_PixalSize;




                        // DestinationRectangle.Offset(GridPanel.AutoScrollPosition);
                        if (TileMap[X, Y] != null)
                        {
                            Rectangle SourceRectangle = Rectangle.Empty;
                            SourceRectangle.X = TileMap[X, Y].PositionX * m_PixalSize.Width;
                            SourceRectangle.Y = TileMap[X, Y].PositionY * m_PixalSize.Height;
                            Size Temp = new Size(m_PixalSize.Width, m_PixalSize.Height);
                            SourceRectangle.Size = Temp;
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
                                Collison.X = (RespawnRectangles[i].X * m_PixalSize.Width) + OffsetScroll.X;
                                Collison.Y = (RespawnRectangles[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
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
                                Collison.X = (CheckPointRectangle[i].X * m_PixalSize.Width) + OffsetScroll.X;
                                Collison.Y = (CheckPointRectangle[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("CP", Collison.X, Collison.Y, Color.Green);
                            }
                        }


                        #endregion



                        #region AI Rectangle ForLoop

                        if (AIRectangles != null)
                        {


                            for (int i = 0; i < AIRectangles.Count; i++)
                            {
                                Rectangle Collison = Rectangle.Empty;
                                Collison.X = (AIRectangles[i].X * m_PixalSize.Width) + OffsetScroll.X;
                                Collison.Y = (AIRectangles[i].Y * m_PixalSize.Height) + OffsetScroll.Y;
                                Collison.Size = m_PixalSize;

                                m_DirectXDraw.DrawHollowRect(Collison, Color.Red, 1);
                                m_DirectXDraw.DrawText("AI", Collison.X, Collison.Y, Color.Yellow);
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
            if (Temp.Height < m_Picture.Height)
            {
                for (int X = 0; X < Temp.Width; X++)
                {
                    for (int Y = 0; Y < Temp.Height; Y++)
                    {
                        TileMap[X, Y] = tileMapTemp[X, Y];
                    }

                }
            }
            else if (Temp.Height > m_Picture.Height)
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
                m_filename = Load.SafeFileName;
                int width = m_Texture.GetTextureWidth(TileImage);
                int height = m_Texture.GetTextureHeight(TileImage);
                Size m_panelSize = new Size(width, height);
                TilePanel.AutoScrollMinSize = m_panelSize;


            }

        }

        private void TilePanel_MouseClick(object sender, MouseEventArgs e)
        {

            if (TileImage != -1)
            {
                CurrentSelectedTile = new TIleClass((e.Location.X - TilePanel.AutoScrollPosition.X) / m_PixalSize.Width, (e.Location.Y - TilePanel.AutoScrollPosition.Y) / m_PixalSize.Height);

                IsSelected = true;
            }

        }

        private void GridPanel_MouseClick(object sender, MouseEventArgs e)
        {
            #region this is a Check for the Left Mosue CLick so that you can Grab a Tile
            if (e.Button == MouseButtons.Left)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;
                if (X >= m_Picture.Width || Y >= m_Picture.Height || X < 0 || Y < 0)
                {
                    return;
                }
                TileMap[X, Y] = CurrentSelectedTile;
                this.Invalidate();
            }
            #endregion


            #region This is a Check for the Right mous click and Radiobutton Collison

            if (e.Button == MouseButtons.Left && m_Collision.Checked == true)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;

                TileMap[X, Y].Collision = 1;

            }
            else
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;

                TileMap[X, Y].Collision = 0;


            }

            #endregion


            #region this is a Check for the Right mouse Click and Radio Button Respawn
            if (e.Button == MouseButtons.Left && m_Spawn.Checked == true)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;

                TileMap[X, Y].SpawnX = e.Location.Y;
                TileMap[X, Y].SpawnY = e.Location.X;

            }
            else
            {
                return;

            }
            #endregion


            #region This is a Check for the Right Mouse Click and Radio Button Respawn
            if (e.Button == MouseButtons.Right && m_CheckPoint.Checked == true)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;

                TileMap[X, Y].CheckPointX = Y;
                TileMap[X, Y].CheckPointY = X;

            }
            else
                return;
            #endregion


            #region This is a Check for the Right Mouse Click and Radio Button Respawn

            if (e.Button == MouseButtons.Right && m_AI.Checked == true)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;




            }
            #endregion





            this.Invalidate();
        }

        private void GridPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int X = (e.Location.X - GridPanel.AutoScrollPosition.X) / m_PixalSize.Width;
                int Y = (e.Location.Y - GridPanel.AutoScrollPosition.Y) / m_PixalSize.Height;
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

        private void ImageWidth_ValueChanged(object sender, EventArgs e)
        {
        }

        private void ImageHeight_ValueChanged(object sender, EventArgs e)
        {

        }

        private void saveXMLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
            SaveFileDialog Save = new SaveFileDialog();
            Save.Filter = "All Files|*.*|Xml Files|*.xml";
            Save.FilterIndex = 2;
            Save.DefaultExt = ".xml";
            // Load.Filter = "All Files(*.*)|*.*|My Files(*.myf)|*.myf";
            if (DialogResult.OK == Save.ShowDialog())
            {
                XDocument Doc = new XDocument();
                int width = m_Texture.GetTextureWidth(TileImage);
                int height = m_Texture.GetTextureHeight(TileImage);
                Size sz = new Size(width / m_PixalSize.Width,
                     height / m_PixalSize.Height);
                XElement m_Element = new XElement("Map");
                XAttribute m_Name = new XAttribute("Image", m_filename);
                XAttribute m_MapHeight = new XAttribute("MapHeight", m_Picture.Height);
                XAttribute m_MapWidth = new XAttribute("MapWidth", m_Picture.Width);
                XAttribute m_PixalHeight = new XAttribute("TileHeight", m_PixalSize.Height);
                XAttribute m_PixalWidth = new XAttribute("TileWidth", m_PixalSize.Width);
                XAttribute m_ImageHeight = new XAttribute("ImageHeight", m_Texture.GetTextureHeight(TileImage));
                XAttribute m_ImageWidth = new XAttribute("ImageWidth", m_Texture.GetTextureWidth(TileImage));
                m_Element.Add(m_Name);
                m_Element.Add(m_MapHeight);
                m_Element.Add(m_MapWidth);
                m_Element.Add(m_PixalHeight);
                m_Element.Add(m_PixalWidth);
                m_Element.Add(m_ImageHeight);
                m_Element.Add(m_ImageWidth);

                int y = 0;
                for (int X = 0; X < m_Picture.Width; X++)
                {
                    for (int Y = 0; Y < m_Picture.Height; Y++)
                    {
                        XElement Tile_Element = new XElement("Tile");
                        XAttribute m_PositionX = new XAttribute("PositionX", X);
                        XAttribute m_PositionY = new XAttribute("PositionY", Y);

                        y = (TileMap[X, Y].PositionY * sz.Width) + TileMap[X, Y].PositionX;

                        XAttribute m_ID = new XAttribute("TileID", y);
                        XAttribute m_Collision = new XAttribute("TileCollision", TileMap[X, Y].Collision);
                        XAttribute m_SpawnX = new XAttribute("SpawnX", TileMap[X, Y].SpawnX);
                        XAttribute m_SpawnY = new XAttribute("SpawnY", TileMap[X, Y].SpawnY);
                        XAttribute m_CheckPointX = new XAttribute("CheckPointX", TileMap[X, Y].CheckPointX);
                        XAttribute m_CheckPointY = new XAttribute("CheckPointY", TileMap[X, Y].CheckPointY);
                        if (TileMap[X, Y].Triggerevent != null)
                        {
                            XAttribute m_Trigger = new XAttribute("TriggerEvents", TileMap[X, Y].Triggerevent);
                            Tile_Element.Add(m_Trigger);
                        }

                        XAttribute Tilem_PositionX = new XAttribute("TilePositionX", TileMap[X, Y].PositionX);
                        XAttribute Tilem_PositionY = new XAttribute("TilePositionY", TileMap[X, Y].PositionY);

                        Tile_Element.Add(m_PositionX);
                        Tile_Element.Add(m_PositionY);
                        Tile_Element.Add(m_ID);
                        Tile_Element.Add(m_Collision);
                        Tile_Element.Add(m_SpawnX);
                        Tile_Element.Add(m_SpawnY);
                        Tile_Element.Add(m_CheckPointX);
                        Tile_Element.Add(m_CheckPointY);
                        Tile_Element.Add(Tilem_PositionX);
                        Tile_Element.Add(Tilem_PositionY);
                        m_Element.Add(Tile_Element);


                    }
                }

                Doc.Add(m_Element);
                Doc.Save(Save.FileName);


            }

        }

        private void ImagePixalHeight_ValueChanged(object sender, EventArgs e)
        {
        }

        private void ImagePixalWidth_ValueChanged(object sender, EventArgs e)
        {

        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog Load = new OpenFileDialog();
            Load.Filter = "All Files|*.*|Xml Files|*.xml";
            Load.FilterIndex = 2;
            Load.DefaultExt = ".xml";

            // Load.Filter = "All Files(*.*)|*.*|My Files(*.myf)|*.myf";
            if (DialogResult.OK == Load.ShowDialog())
            {
                XDocument Doc = XDocument.Load(Load.FileName);
                XElement m_Element = Doc.Element("Map");
                XAttribute m_Attribute = m_Element.Attribute("Image");
                m_filename = m_Attribute.Value;
                TileImage = m_Texture.LoadTexture(m_filename);
                m_Attribute = m_Element.Attribute("MapHeight");
                m_Picture.Height = int.Parse(m_Attribute.Value);
                m_Attribute = m_Element.Attribute("MapWidth");
                m_Picture.Width = int.Parse(m_Attribute.Value);
                m_Attribute = m_Element.Attribute("TileHeight");
                m_PixalSize.Height = int.Parse(m_Attribute.Value);
                m_Attribute = m_Element.Attribute("TileWidth");
                m_PixalSize.Width = int.Parse(m_Attribute.Value);
                m_Attribute = m_Element.Attribute("ImageHeight");
                TileMap = new TIleClass[m_Picture.Width, m_Picture.Height];
                XElement m_element = m_Element.Element("Tile");
                int width = m_Texture.GetTextureWidth(TileImage);
                int height = m_Texture.GetTextureHeight(TileImage);
                Size sz = new Size(width / m_PixalSize.Width,
                     height / m_PixalSize.Height);
                TilePanel.AutoScrollMinSize = sz;
                GridPanel.AutoScrollMinSize = m_Picture;
                //TIleClass m_Tiles = new TIleClass(m_Picture.Width, m_Picture.Height);
                //TIleClass[,] tileMapTemp = new TIleClass[m_Picture.Width, m_Picture.Height];
                int X = 0;
                int Y = 0;
                foreach (XElement m_XElement in m_Element.Elements())
                {
                    TIleClass m_Tiles = new TIleClass(m_Picture.Width, m_Picture.Height);
                    m_Attribute = m_XElement.Attribute("TilePositionX");
                    m_Tiles.PositionX = int.Parse(m_Attribute.Value);
                    // m_Tiles.PositionX *= m_PixalSize.Height;
                    m_Attribute = m_XElement.Attribute("TilePositionY");
                    m_Tiles.PositionY = int.Parse(m_Attribute.Value);
                    //m_Tiles.PositionY *= m_PixalSize.Width;
                    m_Attribute = m_XElement.Attribute("TileID");
                    m_Tiles.m_ID = int.Parse(m_Attribute.Value);

                    m_Attribute = m_XElement.Attribute("TileCollision");
                    m_Tiles.Collision = int.Parse(m_Attribute.Value);

                    m_Attribute = m_XElement.Attribute("SpawnX");
                    m_Tiles.SpawnX = int.Parse(m_Attribute.Value);

                    m_Attribute = m_XElement.Attribute("SpawnY");
                    m_Tiles.SpawnY = int.Parse(m_Attribute.Value);


                    m_Attribute = m_XElement.Attribute("CheckPointX");
                    m_Tiles.CheckPointX = int.Parse(m_Attribute.Value);

                    m_Attribute = m_XElement.Attribute("CheckPointY");
                    m_Tiles.CheckPointY = int.Parse(m_Attribute.Value);


                    TileMap[X, Y] = m_Tiles;
                    Y++;
                    if (Y >= m_Picture.Height)
                    {
                        X++;
                        Y = 0;
                    }



                    if (X > m_Picture.Width)
                        return;

                }








            }


            //Doc.Add();
            //m_element.




        }
    }



}
