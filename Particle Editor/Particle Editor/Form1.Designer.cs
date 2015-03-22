namespace Particle_Editor
{
    partial class ParticleEditor
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ParticleEditor));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.loadImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.customizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.particlePropGroup = new System.Windows.Forms.GroupBox();
            this.rotEndLabel = new System.Windows.Forms.Label();
            this.rotEndNum = new System.Windows.Forms.NumericUpDown();
            this.rotStartLabel = new System.Windows.Forms.Label();
            this.rotStartNum = new System.Windows.Forms.NumericUpDown();
            this.bloomButton = new System.Windows.Forms.Button();
            this.continuousCheck = new System.Windows.Forms.CheckBox();
            this.colorEndButton = new System.Windows.Forms.Button();
            this.colorStartButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.scaleEndNum = new System.Windows.Forms.NumericUpDown();
            this.scaleStartLabel = new System.Windows.Forms.Label();
            this.scaleStartNum = new System.Windows.Forms.NumericUpDown();
            this.spawnRateNum = new System.Windows.Forms.NumericUpDown();
            this.spawnRateLabel = new System.Windows.Forms.Label();
            this.maximumPNum = new System.Windows.Forms.NumericUpDown();
            this.maximumPLabel = new System.Windows.Forms.Label();
            this.maxLifeNum = new System.Windows.Forms.NumericUpDown();
            this.minLifeNum = new System.Windows.Forms.NumericUpDown();
            this.maxLifeLabel = new System.Windows.Forms.Label();
            this.minLifeLabel = new System.Windows.Forms.Label();
            this.velYNegLabel = new System.Windows.Forms.Label();
            this.velYPosLabel = new System.Windows.Forms.Label();
            this.velXNegLabel = new System.Windows.Forms.Label();
            this.velocityYNegNum = new System.Windows.Forms.NumericUpDown();
            this.velocityYPosNum = new System.Windows.Forms.NumericUpDown();
            this.velocityXNegNum = new System.Windows.Forms.NumericUpDown();
            this.velocityXPosNum = new System.Windows.Forms.NumericUpDown();
            this.velXPosLabel = new System.Windows.Forms.Label();
            this.emitterRectGroup = new System.Windows.Forms.GroupBox();
            this.showRectCheck = new System.Windows.Forms.CheckBox();
            this.rectYLabel = new System.Windows.Forms.Label();
            this.rectXLabel = new System.Windows.Forms.Label();
            this.emitterRectXPosNum = new System.Windows.Forms.NumericUpDown();
            this.emitterRectYPosNum = new System.Windows.Forms.NumericUpDown();
            this.rectHeightLabel = new System.Windows.Forms.Label();
            this.rectWidthLabel = new System.Windows.Forms.Label();
            this.emitterRectWidthNum = new System.Windows.Forms.NumericUpDown();
            this.emitterRectHeightNum = new System.Windows.Forms.NumericUpDown();
            this.GraphicsPanel = new System.Windows.Forms.Panel();
            this.CurrentTimer = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.particlePropGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.rotEndNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.rotStartNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleEndNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleStartNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.spawnRateNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.maximumPNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxLifeNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.minLifeNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYNegNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYPosNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXNegNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXPosNum)).BeginInit();
            this.emitterRectGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectXPosNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectYPosNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectWidthNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectHeightNum)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.optionsToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.aboutToolStripMenuItem1});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(858, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.toolStripSeparator,
            this.saveToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripMenuItem.Image")));
            this.openToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.openToolStripMenuItem.Size = new System.Drawing.Size(175, 24);
            this.openToolStripMenuItem.Text = "&Open";
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(172, 6);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("saveToolStripMenuItem.Image")));
            this.saveToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(175, 24);
            this.saveToolStripMenuItem.Text = "&Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(175, 24);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // optionsToolStripMenuItem
            // 
            this.optionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSeparator3,
            this.loadImageToolStripMenuItem});
            this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
            this.optionsToolStripMenuItem.Size = new System.Drawing.Size(73, 24);
            this.optionsToolStripMenuItem.Text = "&Options";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(207, 6);
            // 
            // loadImageToolStripMenuItem
            // 
            this.loadImageToolStripMenuItem.Name = "loadImageToolStripMenuItem";
            this.loadImageToolStripMenuItem.Size = new System.Drawing.Size(210, 24);
            this.loadImageToolStripMenuItem.Text = "&Load Particle Image";
            this.loadImageToolStripMenuItem.Click += new System.EventHandler(this.loadImageToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.customizeToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(57, 24);
            this.toolsToolStripMenuItem.Text = "&Tools";
            // 
            // customizeToolStripMenuItem
            // 
            this.customizeToolStripMenuItem.Name = "customizeToolStripMenuItem";
            this.customizeToolStripMenuItem.Size = new System.Drawing.Size(175, 24);
            this.customizeToolStripMenuItem.Text = "&Customize";
            // 
            // aboutToolStripMenuItem1
            // 
            this.aboutToolStripMenuItem1.Name = "aboutToolStripMenuItem1";
            this.aboutToolStripMenuItem1.Size = new System.Drawing.Size(62, 24);
            this.aboutToolStripMenuItem1.Text = "&About";
            this.aboutToolStripMenuItem1.Click += new System.EventHandler(this.aboutToolStripMenuItem1_Click);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 28);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.particlePropGroup);
            this.splitContainer1.Panel1.Controls.Add(this.emitterRectGroup);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.GraphicsPanel);
            this.splitContainer1.Size = new System.Drawing.Size(858, 738);
            this.splitContainer1.SplitterDistance = 286;
            this.splitContainer1.TabIndex = 1;
            // 
            // particlePropGroup
            // 
            this.particlePropGroup.Controls.Add(this.rotEndLabel);
            this.particlePropGroup.Controls.Add(this.rotEndNum);
            this.particlePropGroup.Controls.Add(this.rotStartLabel);
            this.particlePropGroup.Controls.Add(this.rotStartNum);
            this.particlePropGroup.Controls.Add(this.bloomButton);
            this.particlePropGroup.Controls.Add(this.continuousCheck);
            this.particlePropGroup.Controls.Add(this.colorEndButton);
            this.particlePropGroup.Controls.Add(this.colorStartButton);
            this.particlePropGroup.Controls.Add(this.label2);
            this.particlePropGroup.Controls.Add(this.scaleEndNum);
            this.particlePropGroup.Controls.Add(this.scaleStartLabel);
            this.particlePropGroup.Controls.Add(this.scaleStartNum);
            this.particlePropGroup.Controls.Add(this.spawnRateNum);
            this.particlePropGroup.Controls.Add(this.spawnRateLabel);
            this.particlePropGroup.Controls.Add(this.maximumPNum);
            this.particlePropGroup.Controls.Add(this.maximumPLabel);
            this.particlePropGroup.Controls.Add(this.maxLifeNum);
            this.particlePropGroup.Controls.Add(this.minLifeNum);
            this.particlePropGroup.Controls.Add(this.maxLifeLabel);
            this.particlePropGroup.Controls.Add(this.minLifeLabel);
            this.particlePropGroup.Controls.Add(this.velYNegLabel);
            this.particlePropGroup.Controls.Add(this.velYPosLabel);
            this.particlePropGroup.Controls.Add(this.velXNegLabel);
            this.particlePropGroup.Controls.Add(this.velocityYNegNum);
            this.particlePropGroup.Controls.Add(this.velocityYPosNum);
            this.particlePropGroup.Controls.Add(this.velocityXNegNum);
            this.particlePropGroup.Controls.Add(this.velocityXPosNum);
            this.particlePropGroup.Controls.Add(this.velXPosLabel);
            this.particlePropGroup.Location = new System.Drawing.Point(4, 199);
            this.particlePropGroup.Name = "particlePropGroup";
            this.particlePropGroup.Size = new System.Drawing.Size(278, 527);
            this.particlePropGroup.TabIndex = 1;
            this.particlePropGroup.TabStop = false;
            this.particlePropGroup.Text = "Particle Properties";
            // 
            // rotEndLabel
            // 
            this.rotEndLabel.AutoSize = true;
            this.rotEndLabel.Location = new System.Drawing.Point(8, 386);
            this.rotEndLabel.Name = "rotEndLabel";
            this.rotEndLabel.Size = new System.Drawing.Size(130, 17);
            this.rotEndLabel.TabIndex = 31;
            this.rotEndLabel.Text = "Rotation End (Deg)";
            // 
            // rotEndNum
            // 
            this.rotEndNum.Location = new System.Drawing.Point(144, 384);
            this.rotEndNum.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.rotEndNum.Name = "rotEndNum";
            this.rotEndNum.Size = new System.Drawing.Size(120, 22);
            this.rotEndNum.TabIndex = 30;
            // 
            // rotStartLabel
            // 
            this.rotStartLabel.AutoSize = true;
            this.rotStartLabel.Location = new System.Drawing.Point(8, 350);
            this.rotStartLabel.Name = "rotStartLabel";
            this.rotStartLabel.Size = new System.Drawing.Size(135, 17);
            this.rotStartLabel.TabIndex = 29;
            this.rotStartLabel.Text = "Rotation Start (Deg)";
            // 
            // rotStartNum
            // 
            this.rotStartNum.Location = new System.Drawing.Point(144, 348);
            this.rotStartNum.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.rotStartNum.Name = "rotStartNum";
            this.rotStartNum.Size = new System.Drawing.Size(120, 22);
            this.rotStartNum.TabIndex = 28;
            // 
            // bloomButton
            // 
            this.bloomButton.Location = new System.Drawing.Point(144, 58);
            this.bloomButton.Name = "bloomButton";
            this.bloomButton.Size = new System.Drawing.Size(120, 23);
            this.bloomButton.TabIndex = 0;
            this.bloomButton.Text = "Bloom";
            this.bloomButton.UseVisualStyleBackColor = true;
            this.bloomButton.Click += new System.EventHandler(this.bloomButton_Click);
            // 
            // continuousCheck
            // 
            this.continuousCheck.AutoSize = true;
            this.continuousCheck.Checked = true;
            this.continuousCheck.CheckState = System.Windows.Forms.CheckState.Checked;
            this.continuousCheck.Location = new System.Drawing.Point(11, 58);
            this.continuousCheck.Name = "continuousCheck";
            this.continuousCheck.Size = new System.Drawing.Size(101, 21);
            this.continuousCheck.TabIndex = 27;
            this.continuousCheck.Text = "Continuous";
            this.continuousCheck.UseVisualStyleBackColor = true;
            this.continuousCheck.CheckedChanged += new System.EventHandler(this.continuousCheck_CheckedChanged);
            // 
            // colorEndButton
            // 
            this.colorEndButton.Location = new System.Drawing.Point(144, 492);
            this.colorEndButton.Name = "colorEndButton";
            this.colorEndButton.Size = new System.Drawing.Size(96, 23);
            this.colorEndButton.TabIndex = 26;
            this.colorEndButton.Text = "Color End";
            this.colorEndButton.UseVisualStyleBackColor = true;
            this.colorEndButton.Click += new System.EventHandler(this.colorEndButton_Click);
            // 
            // colorStartButton
            // 
            this.colorStartButton.Location = new System.Drawing.Point(18, 492);
            this.colorStartButton.Name = "colorStartButton";
            this.colorStartButton.Size = new System.Drawing.Size(102, 23);
            this.colorStartButton.TabIndex = 25;
            this.colorStartButton.Text = "Color Start";
            this.colorStartButton.UseVisualStyleBackColor = true;
            this.colorStartButton.Click += new System.EventHandler(this.colorStartButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 317);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 17);
            this.label2.TabIndex = 24;
            this.label2.Text = "Scale End";
            // 
            // scaleEndNum
            // 
            this.scaleEndNum.DecimalPlaces = 3;
            this.scaleEndNum.Increment = new decimal(new int[] {
            100,
            0,
            0,
            196608});
            this.scaleEndNum.Location = new System.Drawing.Point(144, 315);
            this.scaleEndNum.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.scaleEndNum.Name = "scaleEndNum";
            this.scaleEndNum.Size = new System.Drawing.Size(120, 22);
            this.scaleEndNum.TabIndex = 23;
            this.scaleEndNum.Value = new decimal(new int[] {
            1500,
            0,
            0,
            196608});
            // 
            // scaleStartLabel
            // 
            this.scaleStartLabel.AutoSize = true;
            this.scaleStartLabel.Location = new System.Drawing.Point(8, 281);
            this.scaleStartLabel.Name = "scaleStartLabel";
            this.scaleStartLabel.Size = new System.Drawing.Size(77, 17);
            this.scaleStartLabel.TabIndex = 21;
            this.scaleStartLabel.Text = "Scale Start";
            // 
            // scaleStartNum
            // 
            this.scaleStartNum.DecimalPlaces = 3;
            this.scaleStartNum.Increment = new decimal(new int[] {
            100,
            0,
            0,
            196608});
            this.scaleStartNum.Location = new System.Drawing.Point(144, 279);
            this.scaleStartNum.Maximum = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.scaleStartNum.Name = "scaleStartNum";
            this.scaleStartNum.Size = new System.Drawing.Size(120, 22);
            this.scaleStartNum.TabIndex = 19;
            this.scaleStartNum.Value = new decimal(new int[] {
            300,
            0,
            0,
            196608});
            // 
            // spawnRateNum
            // 
            this.spawnRateNum.Location = new System.Drawing.Point(144, 94);
            this.spawnRateNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.spawnRateNum.Name = "spawnRateNum";
            this.spawnRateNum.Size = new System.Drawing.Size(120, 22);
            this.spawnRateNum.TabIndex = 15;
            this.spawnRateNum.Value = new decimal(new int[] {
            50,
            0,
            0,
            0});
            // 
            // spawnRateLabel
            // 
            this.spawnRateLabel.AutoSize = true;
            this.spawnRateLabel.Location = new System.Drawing.Point(8, 96);
            this.spawnRateLabel.Name = "spawnRateLabel";
            this.spawnRateLabel.Size = new System.Drawing.Size(84, 17);
            this.spawnRateLabel.TabIndex = 14;
            this.spawnRateLabel.Text = "Spawn Rate";
            // 
            // maximumPNum
            // 
            this.maximumPNum.Location = new System.Drawing.Point(144, 26);
            this.maximumPNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.maximumPNum.Name = "maximumPNum";
            this.maximumPNum.Size = new System.Drawing.Size(120, 22);
            this.maximumPNum.TabIndex = 13;
            this.maximumPNum.Value = new decimal(new int[] {
            500,
            0,
            0,
            0});
            this.maximumPNum.ValueChanged += new System.EventHandler(this.maximumPNum_ValueChanged);
            // 
            // maximumPLabel
            // 
            this.maximumPLabel.AutoSize = true;
            this.maximumPLabel.Location = new System.Drawing.Point(8, 28);
            this.maximumPLabel.Name = "maximumPLabel";
            this.maximumPLabel.Size = new System.Drawing.Size(124, 17);
            this.maximumPLabel.TabIndex = 12;
            this.maximumPLabel.Text = "Maximum Particles";
            // 
            // maxLifeNum
            // 
            this.maxLifeNum.DecimalPlaces = 3;
            this.maxLifeNum.Increment = new decimal(new int[] {
            100,
            0,
            0,
            196608});
            this.maxLifeNum.Location = new System.Drawing.Point(144, 454);
            this.maxLifeNum.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            196608});
            this.maxLifeNum.Name = "maxLifeNum";
            this.maxLifeNum.Size = new System.Drawing.Size(120, 22);
            this.maxLifeNum.TabIndex = 11;
            this.maxLifeNum.Value = new decimal(new int[] {
            15,
            0,
            0,
            65536});
            this.maxLifeNum.ValueChanged += new System.EventHandler(this.maxLifeNum_ValueChanged);
            // 
            // minLifeNum
            // 
            this.minLifeNum.DecimalPlaces = 3;
            this.minLifeNum.Increment = new decimal(new int[] {
            100,
            0,
            0,
            196608});
            this.minLifeNum.Location = new System.Drawing.Point(144, 418);
            this.minLifeNum.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            196608});
            this.minLifeNum.Name = "minLifeNum";
            this.minLifeNum.Size = new System.Drawing.Size(120, 22);
            this.minLifeNum.TabIndex = 10;
            this.minLifeNum.Value = new decimal(new int[] {
            8,
            0,
            0,
            65536});
            this.minLifeNum.ValueChanged += new System.EventHandler(this.minLifeNum_ValueChanged);
            // 
            // maxLifeLabel
            // 
            this.maxLifeLabel.AutoSize = true;
            this.maxLifeLabel.Location = new System.Drawing.Point(8, 456);
            this.maxLifeLabel.Name = "maxLifeLabel";
            this.maxLifeLabel.Size = new System.Drawing.Size(92, 17);
            this.maxLifeLabel.TabIndex = 9;
            this.maxLifeLabel.Text = "Max Life (ms)";
            // 
            // minLifeLabel
            // 
            this.minLifeLabel.AutoSize = true;
            this.minLifeLabel.Location = new System.Drawing.Point(8, 420);
            this.minLifeLabel.Name = "minLifeLabel";
            this.minLifeLabel.Size = new System.Drawing.Size(93, 17);
            this.minLifeLabel.TabIndex = 8;
            this.minLifeLabel.Text = "Min. Life (ms)";
            // 
            // velYNegLabel
            // 
            this.velYNegLabel.AutoSize = true;
            this.velYNegLabel.Location = new System.Drawing.Point(8, 243);
            this.velYNegLabel.Name = "velYNegLabel";
            this.velYNegLabel.Size = new System.Drawing.Size(130, 17);
            this.velYNegLabel.TabIndex = 7;
            this.velYNegLabel.Text = "Velocity Y Negative";
            // 
            // velYPosLabel
            // 
            this.velYPosLabel.AutoSize = true;
            this.velYPosLabel.Location = new System.Drawing.Point(8, 206);
            this.velYPosLabel.Name = "velYPosLabel";
            this.velYPosLabel.Size = new System.Drawing.Size(123, 17);
            this.velYPosLabel.TabIndex = 6;
            this.velYPosLabel.Text = "Velocity Y Positive";
            // 
            // velXNegLabel
            // 
            this.velXNegLabel.AutoSize = true;
            this.velXNegLabel.Location = new System.Drawing.Point(8, 168);
            this.velXNegLabel.Name = "velXNegLabel";
            this.velXNegLabel.Size = new System.Drawing.Size(130, 17);
            this.velXNegLabel.TabIndex = 5;
            this.velXNegLabel.Text = "Velocity X Negative";
            // 
            // velocityYNegNum
            // 
            this.velocityYNegNum.Location = new System.Drawing.Point(144, 241);
            this.velocityYNegNum.Maximum = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.velocityYNegNum.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.velocityYNegNum.Name = "velocityYNegNum";
            this.velocityYNegNum.Size = new System.Drawing.Size(120, 22);
            this.velocityYNegNum.TabIndex = 4;
            this.velocityYNegNum.Value = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            // 
            // velocityYPosNum
            // 
            this.velocityYPosNum.Location = new System.Drawing.Point(144, 204);
            this.velocityYPosNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.velocityYPosNum.Name = "velocityYPosNum";
            this.velocityYPosNum.Size = new System.Drawing.Size(120, 22);
            this.velocityYPosNum.TabIndex = 3;
            this.velocityYPosNum.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // velocityXNegNum
            // 
            this.velocityXNegNum.Location = new System.Drawing.Point(144, 166);
            this.velocityXNegNum.Maximum = new decimal(new int[] {
            0,
            0,
            0,
            0});
            this.velocityXNegNum.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.velocityXNegNum.Name = "velocityXNegNum";
            this.velocityXNegNum.Size = new System.Drawing.Size(120, 22);
            this.velocityXNegNum.TabIndex = 2;
            this.velocityXNegNum.Value = new decimal(new int[] {
            100,
            0,
            0,
            -2147483648});
            // 
            // velocityXPosNum
            // 
            this.velocityXPosNum.Location = new System.Drawing.Point(144, 131);
            this.velocityXPosNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.velocityXPosNum.Name = "velocityXPosNum";
            this.velocityXPosNum.Size = new System.Drawing.Size(120, 22);
            this.velocityXPosNum.TabIndex = 1;
            this.velocityXPosNum.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // velXPosLabel
            // 
            this.velXPosLabel.AutoSize = true;
            this.velXPosLabel.Location = new System.Drawing.Point(8, 133);
            this.velXPosLabel.Name = "velXPosLabel";
            this.velXPosLabel.Size = new System.Drawing.Size(123, 17);
            this.velXPosLabel.TabIndex = 0;
            this.velXPosLabel.Text = "Velocity X Positive";
            // 
            // emitterRectGroup
            // 
            this.emitterRectGroup.Controls.Add(this.showRectCheck);
            this.emitterRectGroup.Controls.Add(this.rectYLabel);
            this.emitterRectGroup.Controls.Add(this.rectXLabel);
            this.emitterRectGroup.Controls.Add(this.emitterRectXPosNum);
            this.emitterRectGroup.Controls.Add(this.emitterRectYPosNum);
            this.emitterRectGroup.Controls.Add(this.rectHeightLabel);
            this.emitterRectGroup.Controls.Add(this.rectWidthLabel);
            this.emitterRectGroup.Controls.Add(this.emitterRectWidthNum);
            this.emitterRectGroup.Controls.Add(this.emitterRectHeightNum);
            this.emitterRectGroup.Location = new System.Drawing.Point(4, 4);
            this.emitterRectGroup.Name = "emitterRectGroup";
            this.emitterRectGroup.Size = new System.Drawing.Size(278, 189);
            this.emitterRectGroup.TabIndex = 0;
            this.emitterRectGroup.TabStop = false;
            this.emitterRectGroup.Text = "Emitter Rectangle";
            // 
            // showRectCheck
            // 
            this.showRectCheck.AutoSize = true;
            this.showRectCheck.Checked = true;
            this.showRectCheck.CheckState = System.Windows.Forms.CheckState.Checked;
            this.showRectCheck.Location = new System.Drawing.Point(45, 150);
            this.showRectCheck.Name = "showRectCheck";
            this.showRectCheck.Size = new System.Drawing.Size(188, 21);
            this.showRectCheck.TabIndex = 8;
            this.showRectCheck.Text = "Show Particle Spawn Box";
            this.showRectCheck.UseVisualStyleBackColor = true;
            this.showRectCheck.CheckedChanged += new System.EventHandler(this.showRectCheck_CheckedChanged);
            // 
            // rectYLabel
            // 
            this.rectYLabel.AutoSize = true;
            this.rectYLabel.Location = new System.Drawing.Point(8, 59);
            this.rectYLabel.Name = "rectYLabel";
            this.rectYLabel.Size = new System.Drawing.Size(85, 17);
            this.rectYLabel.TabIndex = 7;
            this.rectYLabel.Text = "Rectangle Y";
            // 
            // rectXLabel
            // 
            this.rectXLabel.AutoSize = true;
            this.rectXLabel.Location = new System.Drawing.Point(8, 31);
            this.rectXLabel.Name = "rectXLabel";
            this.rectXLabel.Size = new System.Drawing.Size(85, 17);
            this.rectXLabel.TabIndex = 6;
            this.rectXLabel.Text = "Rectangle X";
            // 
            // emitterRectXPosNum
            // 
            this.emitterRectXPosNum.Location = new System.Drawing.Point(131, 29);
            this.emitterRectXPosNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.emitterRectXPosNum.Name = "emitterRectXPosNum";
            this.emitterRectXPosNum.Size = new System.Drawing.Size(120, 22);
            this.emitterRectXPosNum.TabIndex = 5;
            this.emitterRectXPosNum.ValueChanged += new System.EventHandler(this.emitterRectXPos_ValueChanged);
            // 
            // emitterRectYPosNum
            // 
            this.emitterRectYPosNum.Location = new System.Drawing.Point(131, 57);
            this.emitterRectYPosNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.emitterRectYPosNum.Name = "emitterRectYPosNum";
            this.emitterRectYPosNum.Size = new System.Drawing.Size(120, 22);
            this.emitterRectYPosNum.TabIndex = 4;
            this.emitterRectYPosNum.ValueChanged += new System.EventHandler(this.emitterRectYPos_ValueChanged);
            // 
            // rectHeightLabel
            // 
            this.rectHeightLabel.AutoSize = true;
            this.rectHeightLabel.Location = new System.Drawing.Point(8, 115);
            this.rectHeightLabel.Name = "rectHeightLabel";
            this.rectHeightLabel.Size = new System.Drawing.Size(117, 17);
            this.rectHeightLabel.TabIndex = 3;
            this.rectHeightLabel.Text = "Rectangle Height";
            // 
            // rectWidthLabel
            // 
            this.rectWidthLabel.AutoSize = true;
            this.rectWidthLabel.Location = new System.Drawing.Point(8, 87);
            this.rectWidthLabel.Name = "rectWidthLabel";
            this.rectWidthLabel.Size = new System.Drawing.Size(112, 17);
            this.rectWidthLabel.TabIndex = 2;
            this.rectWidthLabel.Text = "Rectangle Width";
            // 
            // emitterRectWidthNum
            // 
            this.emitterRectWidthNum.Location = new System.Drawing.Point(131, 85);
            this.emitterRectWidthNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.emitterRectWidthNum.Name = "emitterRectWidthNum";
            this.emitterRectWidthNum.Size = new System.Drawing.Size(120, 22);
            this.emitterRectWidthNum.TabIndex = 1;
            this.emitterRectWidthNum.ValueChanged += new System.EventHandler(this.emitterRectWidthNum_ValueChanged);
            // 
            // emitterRectHeightNum
            // 
            this.emitterRectHeightNum.Location = new System.Drawing.Point(131, 113);
            this.emitterRectHeightNum.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.emitterRectHeightNum.Name = "emitterRectHeightNum";
            this.emitterRectHeightNum.Size = new System.Drawing.Size(120, 22);
            this.emitterRectHeightNum.TabIndex = 0;
            this.emitterRectHeightNum.ValueChanged += new System.EventHandler(this.emitterRectHeightNum_ValueChanged);
            // 
            // GraphicsPanel
            // 
            this.GraphicsPanel.BackColor = System.Drawing.Color.Black;
            this.GraphicsPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.GraphicsPanel.Location = new System.Drawing.Point(0, 0);
            this.GraphicsPanel.Name = "GraphicsPanel";
            this.GraphicsPanel.Size = new System.Drawing.Size(568, 738);
            this.GraphicsPanel.TabIndex = 0;
            this.GraphicsPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.GraphicsPanel_MouseDown);
            this.GraphicsPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.GraphicsPanel_MouseMove);
            this.GraphicsPanel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.GraphicsPanel_MouseUp);
            // 
            // CurrentTimer
            // 
            this.CurrentTimer.Tick += new System.EventHandler(this.CurrentTimer_Tick);
            // 
            // ParticleEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(858, 766);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "ParticleEditor";
            this.Text = "Particle Editor";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ParticleEditor_FormClosing);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.particlePropGroup.ResumeLayout(false);
            this.particlePropGroup.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.rotEndNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.rotStartNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleEndNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.scaleStartNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.spawnRateNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.maximumPNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxLifeNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.minLifeNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYNegNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYPosNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXNegNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXPosNum)).EndInit();
            this.emitterRectGroup.ResumeLayout(false);
            this.emitterRectGroup.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectXPosNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectYPosNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectWidthNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectHeightNum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem customizeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox emitterRectGroup;
        private System.Windows.Forms.Label rectHeightLabel;
        private System.Windows.Forms.Label rectWidthLabel;
        private System.Windows.Forms.NumericUpDown emitterRectWidthNum;
        private System.Windows.Forms.NumericUpDown emitterRectHeightNum;
        private System.Windows.Forms.Panel GraphicsPanel;
        private System.Windows.Forms.GroupBox particlePropGroup;
        private System.Windows.Forms.Label velYNegLabel;
        private System.Windows.Forms.Label velYPosLabel;
        private System.Windows.Forms.Label velXNegLabel;
        private System.Windows.Forms.NumericUpDown velocityYNegNum;
        private System.Windows.Forms.NumericUpDown velocityYPosNum;
        private System.Windows.Forms.NumericUpDown velocityXNegNum;
        private System.Windows.Forms.NumericUpDown velocityXPosNum;
        private System.Windows.Forms.Label velXPosLabel;
        private System.Windows.Forms.ToolStripMenuItem loadImageToolStripMenuItem;
        private System.Windows.Forms.Label minLifeLabel;
        private System.Windows.Forms.NumericUpDown maxLifeNum;
        private System.Windows.Forms.NumericUpDown minLifeNum;
        private System.Windows.Forms.Label maxLifeLabel;
        private System.Windows.Forms.NumericUpDown maximumPNum;
        private System.Windows.Forms.Label maximumPLabel;
        private System.Windows.Forms.Label rectYLabel;
        private System.Windows.Forms.Label rectXLabel;
        private System.Windows.Forms.NumericUpDown emitterRectXPosNum;
        private System.Windows.Forms.NumericUpDown emitterRectYPosNum;
        private System.Windows.Forms.CheckBox showRectCheck;
        private System.Windows.Forms.Timer CurrentTimer;
        private System.Windows.Forms.NumericUpDown spawnRateNum;
        private System.Windows.Forms.Label spawnRateLabel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown scaleEndNum;
        private System.Windows.Forms.Label scaleStartLabel;
        private System.Windows.Forms.NumericUpDown scaleStartNum;
        private System.Windows.Forms.Button colorEndButton;
        private System.Windows.Forms.Button colorStartButton;
        private System.Windows.Forms.CheckBox continuousCheck;
        private System.Windows.Forms.Button bloomButton;
        private System.Windows.Forms.Label rotEndLabel;
        private System.Windows.Forms.NumericUpDown rotEndNum;
        private System.Windows.Forms.Label rotStartLabel;
        private System.Windows.Forms.NumericUpDown rotStartNum;
    }
}

