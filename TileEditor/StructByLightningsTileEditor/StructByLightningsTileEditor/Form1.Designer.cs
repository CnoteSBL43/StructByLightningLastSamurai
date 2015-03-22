namespace StructByLightningsTileEditor
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.menuStrip2 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveXMLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadTileSetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.GridSizing = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.TilePanel = new System.Windows.Forms.Panel();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.ImagePixalWidth = new System.Windows.Forms.NumericUpDown();
            this.ImagePixalHeight = new System.Windows.Forms.NumericUpDown();
            this.ImagePixal = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.PixalHeight = new System.Windows.Forms.NumericUpDown();
            this.PixalWidth = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.ImageHeight = new System.Windows.Forms.NumericUpDown();
            this.ImageWidth = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.GridHeight = new System.Windows.Forms.NumericUpDown();
            this.GridWidth = new System.Windows.Forms.NumericUpDown();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.panel1 = new System.Windows.Forms.Panel();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.m_Collision = new System.Windows.Forms.CheckBox();
            this.GridPanel = new System.Windows.Forms.Panel();
            this.m_Spawn = new System.Windows.Forms.CheckBox();
            this.m_CheckPoint = new System.Windows.Forms.CheckBox();
            this.m_AI = new System.Windows.Forms.CheckBox();
            this.m_TriggerEvents = new System.Windows.Forms.CheckBox();
            this.menuStrip2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.GridSizing.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ImagePixalWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ImagePixalHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PixalHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PixalWidth)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ImageHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ImageWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridHeight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridWidth)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Location = new System.Drawing.Point(0, 28);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1388, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // menuStrip2
            // 
            this.menuStrip2.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip2.Location = new System.Drawing.Point(0, 0);
            this.menuStrip2.Name = "menuStrip2";
            this.menuStrip2.Size = new System.Drawing.Size(1388, 28);
            this.menuStrip2.TabIndex = 1;
            this.menuStrip2.Text = "menuStrip2";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.saveXMLToolStripMenuItem,
            this.loadTileSetToolStripMenuItem,
            this.toolStripSeparator,
            this.toolStripSeparator1,
            this.toolStripSeparator2});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("newToolStripMenuItem.Image")));
            this.newToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.newToolStripMenuItem.Size = new System.Drawing.Size(171, 26);
            this.newToolStripMenuItem.Text = "&New";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripMenuItem.Image")));
            this.openToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.openToolStripMenuItem.Size = new System.Drawing.Size(171, 26);
            this.openToolStripMenuItem.Text = "&Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // saveXMLToolStripMenuItem
            // 
            this.saveXMLToolStripMenuItem.Name = "saveXMLToolStripMenuItem";
            this.saveXMLToolStripMenuItem.Size = new System.Drawing.Size(171, 26);
            this.saveXMLToolStripMenuItem.Text = "Save XML";
            this.saveXMLToolStripMenuItem.Click += new System.EventHandler(this.saveXMLToolStripMenuItem_Click);
            // 
            // loadTileSetToolStripMenuItem
            // 
            this.loadTileSetToolStripMenuItem.Name = "loadTileSetToolStripMenuItem";
            this.loadTileSetToolStripMenuItem.Size = new System.Drawing.Size(171, 26);
            this.loadTileSetToolStripMenuItem.Text = "LoadTileSet";
            this.loadTileSetToolStripMenuItem.Click += new System.EventHandler(this.loadTileSetToolStripMenuItem_Click);
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(168, 6);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(168, 6);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(168, 6);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 52);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.GridSizing);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.BackColor = System.Drawing.SystemColors.Control;
            this.splitContainer1.Panel2.Controls.Add(this.GridPanel);
            this.splitContainer1.Panel2.ForeColor = System.Drawing.SystemColors.ActiveBorder;
            this.splitContainer1.Size = new System.Drawing.Size(1388, 569);
            this.splitContainer1.SplitterDistance = 461;
            this.splitContainer1.TabIndex = 2;
            // 
            // GridSizing
            // 
            this.GridSizing.Controls.Add(this.tabPage1);
            this.GridSizing.Controls.Add(this.tabPage3);
            this.GridSizing.Controls.Add(this.tabPage2);
            this.GridSizing.Location = new System.Drawing.Point(0, 0);
            this.GridSizing.Name = "GridSizing";
            this.GridSizing.SelectedIndex = 0;
            this.GridSizing.Size = new System.Drawing.Size(459, 569);
            this.GridSizing.TabIndex = 0;
            this.GridSizing.Tag = "";
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.TilePanel);
            this.tabPage1.Controls.Add(this.groupBox2);
            this.tabPage1.Controls.Add(this.groupBox1);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(451, 540);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "GridSizing";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // TilePanel
            // 
            this.TilePanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.TilePanel.Location = new System.Drawing.Point(0, 0);
            this.TilePanel.Name = "TilePanel";
            this.TilePanel.Size = new System.Drawing.Size(451, 373);
            this.TilePanel.TabIndex = 3;
            this.TilePanel.MouseClick += new System.Windows.Forms.MouseEventHandler(this.TilePanel_MouseClick);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.ImagePixalWidth);
            this.groupBox2.Controls.Add(this.ImagePixalHeight);
            this.groupBox2.Controls.Add(this.ImagePixal);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.PixalHeight);
            this.groupBox2.Controls.Add(this.PixalWidth);
            this.groupBox2.Location = new System.Drawing.Point(251, 370);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 167);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Size of Pixals";
            // 
            // ImagePixalWidth
            // 
            this.ImagePixalWidth.Location = new System.Drawing.Point(123, 133);
            this.ImagePixalWidth.Name = "ImagePixalWidth";
            this.ImagePixalWidth.Size = new System.Drawing.Size(71, 22);
            this.ImagePixalWidth.TabIndex = 9;
            this.ImagePixalWidth.ValueChanged += new System.EventHandler(this.ImagePixalWidth_ValueChanged);
            // 
            // ImagePixalHeight
            // 
            this.ImagePixalHeight.Location = new System.Drawing.Point(123, 104);
            this.ImagePixalHeight.Name = "ImagePixalHeight";
            this.ImagePixalHeight.Size = new System.Drawing.Size(71, 22);
            this.ImagePixalHeight.TabIndex = 8;
            this.ImagePixalHeight.ValueChanged += new System.EventHandler(this.ImagePixalHeight_ValueChanged);
            // 
            // ImagePixal
            // 
            this.ImagePixal.AutoSize = true;
            this.ImagePixal.Location = new System.Drawing.Point(1, 138);
            this.ImagePixal.Name = "ImagePixal";
            this.ImagePixal.Size = new System.Drawing.Size(119, 17);
            this.ImagePixal.TabIndex = 7;
            this.ImagePixal.Text = "Image Pixal Width";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(1, 106);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(124, 17);
            this.label7.TabIndex = 6;
            this.label7.Text = "Image Pixal Height";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(82, 17);
            this.label4.TabIndex = 5;
            this.label4.Text = "Pixal Height";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 29);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 17);
            this.label3.TabIndex = 4;
            this.label3.Text = "Pixal Width";
            // 
            // PixalHeight
            // 
            this.PixalHeight.Location = new System.Drawing.Point(123, 62);
            this.PixalHeight.Name = "PixalHeight";
            this.PixalHeight.Size = new System.Drawing.Size(71, 22);
            this.PixalHeight.TabIndex = 2;
            this.PixalHeight.ValueChanged += new System.EventHandler(this.PixalHeight_ValueChanged);
            // 
            // PixalWidth
            // 
            this.PixalWidth.Location = new System.Drawing.Point(123, 31);
            this.PixalWidth.Name = "PixalWidth";
            this.PixalWidth.Size = new System.Drawing.Size(71, 22);
            this.PixalWidth.TabIndex = 1;
            this.PixalWidth.ValueChanged += new System.EventHandler(this.PixalWidth_ValueChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.ImageHeight);
            this.groupBox1.Controls.Add(this.ImageWidth);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.GridHeight);
            this.groupBox1.Controls.Add(this.GridWidth);
            this.groupBox1.Location = new System.Drawing.Point(0, 370);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 167);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Size of Grid";
            // 
            // ImageHeight
            // 
            this.ImageHeight.Location = new System.Drawing.Point(123, 117);
            this.ImageHeight.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.ImageHeight.Name = "ImageHeight";
            this.ImageHeight.Size = new System.Drawing.Size(71, 22);
            this.ImageHeight.TabIndex = 7;
            this.ImageHeight.ValueChanged += new System.EventHandler(this.ImageHeight_ValueChanged);
            // 
            // ImageWidth
            // 
            this.ImageWidth.Location = new System.Drawing.Point(123, 88);
            this.ImageWidth.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.ImageWidth.Name = "ImageWidth";
            this.ImageWidth.Size = new System.Drawing.Size(71, 22);
            this.ImageWidth.TabIndex = 6;
            this.ImageWidth.ValueChanged += new System.EventHandler(this.ImageWidth_ValueChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(3, 117);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(91, 17);
            this.label6.TabIndex = 5;
            this.label6.Text = "Image Height";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 88);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(86, 17);
            this.label5.TabIndex = 4;
            this.label5.Text = "Image Width";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(3, 56);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(80, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "Grid Height";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(75, 17);
            this.label1.TabIndex = 2;
            this.label1.Text = "Grid Width";
            // 
            // GridHeight
            // 
            this.GridHeight.Location = new System.Drawing.Point(123, 57);
            this.GridHeight.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.GridHeight.Name = "GridHeight";
            this.GridHeight.Size = new System.Drawing.Size(71, 22);
            this.GridHeight.TabIndex = 1;
            this.GridHeight.ValueChanged += new System.EventHandler(this.GridHeight_ValueChanged);
            // 
            // GridWidth
            // 
            this.GridWidth.Location = new System.Drawing.Point(123, 29);
            this.GridWidth.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.GridWidth.Name = "GridWidth";
            this.GridWidth.Size = new System.Drawing.Size(71, 22);
            this.GridWidth.TabIndex = 0;
            this.GridWidth.ValueChanged += new System.EventHandler(this.GridWidth_ValueChanged);
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.panel1);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(451, 540);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "tabPage3";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(3, 6);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(442, 443);
            this.panel1.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.m_TriggerEvents);
            this.tabPage2.Controls.Add(this.m_AI);
            this.tabPage2.Controls.Add(this.m_CheckPoint);
            this.tabPage2.Controls.Add(this.m_Spawn);
            this.tabPage2.Controls.Add(this.m_Collision);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(451, 540);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Collision";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // m_Collision
            // 
            this.m_Collision.AutoSize = true;
            this.m_Collision.Location = new System.Drawing.Point(8, 20);
            this.m_Collision.Name = "m_Collision";
            this.m_Collision.Size = new System.Drawing.Size(82, 21);
            this.m_Collision.TabIndex = 8;
            this.m_Collision.Text = "Collision";
            this.m_Collision.UseVisualStyleBackColor = true;
            // 
            // GridPanel
            // 
            this.GridPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.GridPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.GridPanel.Location = new System.Drawing.Point(0, 0);
            this.GridPanel.Name = "GridPanel";
            this.GridPanel.Size = new System.Drawing.Size(923, 569);
            this.GridPanel.TabIndex = 0;
            this.GridPanel.Scroll += new System.Windows.Forms.ScrollEventHandler(this.GridPanel_Scroll);
            this.GridPanel.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GridPanel_MouseClick);
            this.GridPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.GridPanel_MouseMove);
            // 
            // m_Spawn
            // 
            this.m_Spawn.AutoSize = true;
            this.m_Spawn.Location = new System.Drawing.Point(8, 61);
            this.m_Spawn.Name = "m_Spawn";
            this.m_Spawn.Size = new System.Drawing.Size(134, 21);
            this.m_Spawn.TabIndex = 9;
            this.m_Spawn.Text = "Spawn/Respawn";
            this.m_Spawn.UseVisualStyleBackColor = true;
            // 
            // m_CheckPoint
            // 
            this.m_CheckPoint.AutoSize = true;
            this.m_CheckPoint.Location = new System.Drawing.Point(8, 98);
            this.m_CheckPoint.Name = "m_CheckPoint";
            this.m_CheckPoint.Size = new System.Drawing.Size(101, 21);
            this.m_CheckPoint.TabIndex = 10;
            this.m_CheckPoint.Text = "CheckPoint";
            this.m_CheckPoint.UseVisualStyleBackColor = true;
            // 
            // m_AI
            // 
            this.m_AI.AutoSize = true;
            this.m_AI.Location = new System.Drawing.Point(8, 136);
            this.m_AI.Name = "m_AI";
            this.m_AI.Size = new System.Drawing.Size(42, 21);
            this.m_AI.TabIndex = 11;
            this.m_AI.Text = "AI";
            this.m_AI.UseVisualStyleBackColor = true;
            // 
            // m_TriggerEvents
            // 
            this.m_TriggerEvents.AutoSize = true;
            this.m_TriggerEvents.Location = new System.Drawing.Point(8, 180);
            this.m_TriggerEvents.Name = "m_TriggerEvents";
            this.m_TriggerEvents.Size = new System.Drawing.Size(123, 21);
            this.m_TriggerEvents.TabIndex = 12;
            this.m_TriggerEvents.Text = "Trigger Events";
            this.m_TriggerEvents.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1388, 621);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.menuStrip2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.menuStrip2.ResumeLayout(false);
            this.menuStrip2.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.GridSizing.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ImagePixalWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ImagePixalHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PixalHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PixalWidth)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ImageHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ImageWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridHeight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridWidth)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.MenuStrip menuStrip2;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TabControl GridSizing;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown PixalHeight;
        private System.Windows.Forms.NumericUpDown PixalWidth;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown GridHeight;
        private System.Windows.Forms.NumericUpDown GridWidth;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Panel GridPanel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel TilePanel;
        private System.Windows.Forms.ToolStripMenuItem loadTileSetToolStripMenuItem;
        private System.Windows.Forms.NumericUpDown ImageHeight;
        private System.Windows.Forms.NumericUpDown ImageWidth;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ToolStripMenuItem saveXMLToolStripMenuItem;
        private System.Windows.Forms.Label ImagePixal;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown ImagePixalWidth;
        private System.Windows.Forms.NumericUpDown ImagePixalHeight;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.CheckBox m_Collision;
        private System.Windows.Forms.CheckBox m_AI;
        private System.Windows.Forms.CheckBox m_CheckPoint;
        private System.Windows.Forms.CheckBox m_Spawn;
        private System.Windows.Forms.CheckBox m_TriggerEvents;
    }
}

