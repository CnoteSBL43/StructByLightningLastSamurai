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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ParticleEditor));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.loadImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.customizeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contentsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.indexToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.searchToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.particlePropGroup = new System.Windows.Forms.GroupBox();
            this.spawnRateNum = new System.Windows.Forms.NumericUpDown();
            this.spawnR = new System.Windows.Forms.Label();
            this.maxLifeNum = new System.Windows.Forms.NumericUpDown();
            this.minLifeNum = new System.Windows.Forms.NumericUpDown();
            this.maxLife = new System.Windows.Forms.Label();
            this.minLife = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.velYPos = new System.Windows.Forms.Label();
            this.velXNeg = new System.Windows.Forms.Label();
            this.velocityYNegNum = new System.Windows.Forms.NumericUpDown();
            this.velocityYPosNum = new System.Windows.Forms.NumericUpDown();
            this.velocityXNegNum = new System.Windows.Forms.NumericUpDown();
            this.velocityXPosNum = new System.Windows.Forms.NumericUpDown();
            this.velXPos = new System.Windows.Forms.Label();
            this.emitterRectGroup = new System.Windows.Forms.GroupBox();
            this.rectHeight = new System.Windows.Forms.Label();
            this.rectWidth = new System.Windows.Forms.Label();
            this.emitterRectWidthNum = new System.Windows.Forms.NumericUpDown();
            this.emitterRectNum = new System.Windows.Forms.NumericUpDown();
            this.GraphicsPanel = new System.Windows.Forms.Panel();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.particlePropGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.spawnRateNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxLifeNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.minLifeNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYNegNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYPosNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXNegNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXPosNum)).BeginInit();
            this.emitterRectGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectWidthNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectNum)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.optionsToolStripMenuItem,
            this.toolsToolStripMenuItem,
            this.helpToolStripMenuItem,
            this.aboutToolStripMenuItem1});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(826, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.openToolStripMenuItem,
            this.toolStripSeparator,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.exitToolStripMenuItem});
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
            this.newToolStripMenuItem.Size = new System.Drawing.Size(167, 24);
            this.newToolStripMenuItem.Text = "&New";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("openToolStripMenuItem.Image")));
            this.openToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.openToolStripMenuItem.Size = new System.Drawing.Size(167, 24);
            this.openToolStripMenuItem.Text = "&Open";
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(164, 6);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("saveToolStripMenuItem.Image")));
            this.saveToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(167, 24);
            this.saveToolStripMenuItem.Text = "&Save";
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(167, 24);
            this.saveAsToolStripMenuItem.Text = "Save &As";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(167, 24);
            this.exitToolStripMenuItem.Text = "E&xit";
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
            this.toolStripSeparator3.Size = new System.Drawing.Size(154, 6);
            // 
            // loadImageToolStripMenuItem
            // 
            this.loadImageToolStripMenuItem.Name = "loadImageToolStripMenuItem";
            this.loadImageToolStripMenuItem.Size = new System.Drawing.Size(157, 24);
            this.loadImageToolStripMenuItem.Text = "&Load Image";
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
            this.customizeToolStripMenuItem.Size = new System.Drawing.Size(147, 24);
            this.customizeToolStripMenuItem.Text = "&Customize";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.contentsToolStripMenuItem,
            this.indexToolStripMenuItem,
            this.searchToolStripMenuItem,
            this.toolStripSeparator5,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(53, 24);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // contentsToolStripMenuItem
            // 
            this.contentsToolStripMenuItem.Name = "contentsToolStripMenuItem";
            this.contentsToolStripMenuItem.Size = new System.Drawing.Size(136, 24);
            this.contentsToolStripMenuItem.Text = "&Contents";
            // 
            // indexToolStripMenuItem
            // 
            this.indexToolStripMenuItem.Name = "indexToolStripMenuItem";
            this.indexToolStripMenuItem.Size = new System.Drawing.Size(136, 24);
            this.indexToolStripMenuItem.Text = "&Index";
            // 
            // searchToolStripMenuItem
            // 
            this.searchToolStripMenuItem.Name = "searchToolStripMenuItem";
            this.searchToolStripMenuItem.Size = new System.Drawing.Size(136, 24);
            this.searchToolStripMenuItem.Text = "&Search";
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(133, 6);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(136, 24);
            this.aboutToolStripMenuItem.Text = "&About...";
            // 
            // aboutToolStripMenuItem1
            // 
            this.aboutToolStripMenuItem1.Name = "aboutToolStripMenuItem1";
            this.aboutToolStripMenuItem1.Size = new System.Drawing.Size(62, 24);
            this.aboutToolStripMenuItem1.Text = "&About";
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
            this.splitContainer1.Size = new System.Drawing.Size(826, 608);
            this.splitContainer1.SplitterDistance = 276;
            this.splitContainer1.TabIndex = 1;
            // 
            // particlePropGroup
            // 
            this.particlePropGroup.Controls.Add(this.spawnRateNum);
            this.particlePropGroup.Controls.Add(this.spawnR);
            this.particlePropGroup.Controls.Add(this.maxLifeNum);
            this.particlePropGroup.Controls.Add(this.minLifeNum);
            this.particlePropGroup.Controls.Add(this.maxLife);
            this.particlePropGroup.Controls.Add(this.minLife);
            this.particlePropGroup.Controls.Add(this.label4);
            this.particlePropGroup.Controls.Add(this.velYPos);
            this.particlePropGroup.Controls.Add(this.velXNeg);
            this.particlePropGroup.Controls.Add(this.velocityYNegNum);
            this.particlePropGroup.Controls.Add(this.velocityYPosNum);
            this.particlePropGroup.Controls.Add(this.velocityXNegNum);
            this.particlePropGroup.Controls.Add(this.velocityXPosNum);
            this.particlePropGroup.Controls.Add(this.velXPos);
            this.particlePropGroup.Location = new System.Drawing.Point(4, 122);
            this.particlePropGroup.Name = "particlePropGroup";
            this.particlePropGroup.Size = new System.Drawing.Size(268, 304);
            this.particlePropGroup.TabIndex = 1;
            this.particlePropGroup.TabStop = false;
            this.particlePropGroup.Text = "Particle Properties";
            // 
            // spawnRateNum
            // 
            this.spawnRateNum.Location = new System.Drawing.Point(144, 26);
            this.spawnRateNum.Name = "spawnRateNum";
            this.spawnRateNum.Size = new System.Drawing.Size(120, 22);
            this.spawnRateNum.TabIndex = 13;
            // 
            // spawnR
            // 
            this.spawnR.AutoSize = true;
            this.spawnR.Location = new System.Drawing.Point(8, 28);
            this.spawnR.Name = "spawnR";
            this.spawnR.Size = new System.Drawing.Size(84, 17);
            this.spawnR.TabIndex = 12;
            this.spawnR.Text = "Spawn Rate";
            // 
            // maxLifeNum
            // 
            this.maxLifeNum.Location = new System.Drawing.Point(144, 241);
            this.maxLifeNum.Name = "maxLifeNum";
            this.maxLifeNum.Size = new System.Drawing.Size(120, 22);
            this.maxLifeNum.TabIndex = 11;
            // 
            // minLifeNum
            // 
            this.minLifeNum.Location = new System.Drawing.Point(144, 205);
            this.minLifeNum.Name = "minLifeNum";
            this.minLifeNum.Size = new System.Drawing.Size(120, 22);
            this.minLifeNum.TabIndex = 10;
            // 
            // maxLife
            // 
            this.maxLife.AutoSize = true;
            this.maxLife.Location = new System.Drawing.Point(8, 243);
            this.maxLife.Name = "maxLife";
            this.maxLife.Size = new System.Drawing.Size(129, 17);
            this.maxLife.TabIndex = 9;
            this.maxLife.Text = "Max Life (Seconds)";
            // 
            // minLife
            // 
            this.minLife.AutoSize = true;
            this.minLife.Location = new System.Drawing.Point(8, 207);
            this.minLife.Name = "minLife";
            this.minLife.Size = new System.Drawing.Size(130, 17);
            this.minLife.TabIndex = 8;
            this.minLife.Text = "Min. Life (Seconds)";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 172);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(130, 17);
            this.label4.TabIndex = 7;
            this.label4.Text = "Velocity Y Negative";
            // 
            // velYPos
            // 
            this.velYPos.AutoSize = true;
            this.velYPos.Location = new System.Drawing.Point(8, 135);
            this.velYPos.Name = "velYPos";
            this.velYPos.Size = new System.Drawing.Size(123, 17);
            this.velYPos.TabIndex = 6;
            this.velYPos.Text = "Velocity Y Positive";
            // 
            // velXNeg
            // 
            this.velXNeg.AutoSize = true;
            this.velXNeg.Location = new System.Drawing.Point(8, 97);
            this.velXNeg.Name = "velXNeg";
            this.velXNeg.Size = new System.Drawing.Size(130, 17);
            this.velXNeg.TabIndex = 5;
            this.velXNeg.Text = "Velocity X Negative";
            // 
            // velocityYNegNum
            // 
            this.velocityYNegNum.Location = new System.Drawing.Point(144, 170);
            this.velocityYNegNum.Name = "velocityYNegNum";
            this.velocityYNegNum.Size = new System.Drawing.Size(120, 22);
            this.velocityYNegNum.TabIndex = 4;
            // 
            // velocityYPosNum
            // 
            this.velocityYPosNum.Location = new System.Drawing.Point(144, 133);
            this.velocityYPosNum.Name = "velocityYPosNum";
            this.velocityYPosNum.Size = new System.Drawing.Size(120, 22);
            this.velocityYPosNum.TabIndex = 3;
            // 
            // velocityXNegNum
            // 
            this.velocityXNegNum.Location = new System.Drawing.Point(144, 95);
            this.velocityXNegNum.Name = "velocityXNegNum";
            this.velocityXNegNum.Size = new System.Drawing.Size(120, 22);
            this.velocityXNegNum.TabIndex = 2;
            // 
            // velocityXPosNum
            // 
            this.velocityXPosNum.Location = new System.Drawing.Point(144, 60);
            this.velocityXPosNum.Name = "velocityXPosNum";
            this.velocityXPosNum.Size = new System.Drawing.Size(120, 22);
            this.velocityXPosNum.TabIndex = 1;
            // 
            // velXPos
            // 
            this.velXPos.AutoSize = true;
            this.velXPos.Location = new System.Drawing.Point(8, 62);
            this.velXPos.Name = "velXPos";
            this.velXPos.Size = new System.Drawing.Size(123, 17);
            this.velXPos.TabIndex = 0;
            this.velXPos.Text = "Velocity X Positive";
            // 
            // emitterRectGroup
            // 
            this.emitterRectGroup.Controls.Add(this.rectHeight);
            this.emitterRectGroup.Controls.Add(this.rectWidth);
            this.emitterRectGroup.Controls.Add(this.emitterRectWidthNum);
            this.emitterRectGroup.Controls.Add(this.emitterRectNum);
            this.emitterRectGroup.Location = new System.Drawing.Point(4, 4);
            this.emitterRectGroup.Name = "emitterRectGroup";
            this.emitterRectGroup.Size = new System.Drawing.Size(268, 112);
            this.emitterRectGroup.TabIndex = 0;
            this.emitterRectGroup.TabStop = false;
            this.emitterRectGroup.Text = "Emitter Rectangle";
            // 
            // rectHeight
            // 
            this.rectHeight.AutoSize = true;
            this.rectHeight.Location = new System.Drawing.Point(8, 67);
            this.rectHeight.Name = "rectHeight";
            this.rectHeight.Size = new System.Drawing.Size(117, 17);
            this.rectHeight.TabIndex = 3;
            this.rectHeight.Text = "Rectangle Height";
            // 
            // rectWidth
            // 
            this.rectWidth.AutoSize = true;
            this.rectWidth.Location = new System.Drawing.Point(8, 39);
            this.rectWidth.Name = "rectWidth";
            this.rectWidth.Size = new System.Drawing.Size(112, 17);
            this.rectWidth.TabIndex = 2;
            this.rectWidth.Text = "Rectangle Width";
            // 
            // emitterRectWidthNum
            // 
            this.emitterRectWidthNum.Location = new System.Drawing.Point(131, 37);
            this.emitterRectWidthNum.Name = "emitterRectWidthNum";
            this.emitterRectWidthNum.Size = new System.Drawing.Size(120, 22);
            this.emitterRectWidthNum.TabIndex = 1;
            // 
            // emitterRectNum
            // 
            this.emitterRectNum.Location = new System.Drawing.Point(131, 65);
            this.emitterRectNum.Name = "emitterRectNum";
            this.emitterRectNum.Size = new System.Drawing.Size(120, 22);
            this.emitterRectNum.TabIndex = 0;
            // 
            // GraphicsPanel
            // 
            this.GraphicsPanel.BackColor = System.Drawing.Color.Black;
            this.GraphicsPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.GraphicsPanel.Location = new System.Drawing.Point(0, 0);
            this.GraphicsPanel.Name = "GraphicsPanel";
            this.GraphicsPanel.Size = new System.Drawing.Size(546, 608);
            this.GraphicsPanel.TabIndex = 0;
            // 
            // ParticleEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(826, 636);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.menuStrip1);
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
            ((System.ComponentModel.ISupportInitialize)(this.spawnRateNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.maxLifeNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.minLifeNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYNegNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityYPosNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXNegNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.velocityXPosNum)).EndInit();
            this.emitterRectGroup.ResumeLayout(false);
            this.emitterRectGroup.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectWidthNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.emitterRectNum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem customizeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem contentsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem indexToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem searchToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox emitterRectGroup;
        private System.Windows.Forms.Label rectHeight;
        private System.Windows.Forms.Label rectWidth;
        private System.Windows.Forms.NumericUpDown emitterRectWidthNum;
        private System.Windows.Forms.NumericUpDown emitterRectNum;
        private System.Windows.Forms.Panel GraphicsPanel;
        private System.Windows.Forms.GroupBox particlePropGroup;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label velYPos;
        private System.Windows.Forms.Label velXNeg;
        private System.Windows.Forms.NumericUpDown velocityYNegNum;
        private System.Windows.Forms.NumericUpDown velocityYPosNum;
        private System.Windows.Forms.NumericUpDown velocityXNegNum;
        private System.Windows.Forms.NumericUpDown velocityXPosNum;
        private System.Windows.Forms.Label velXPos;
        private System.Windows.Forms.ToolStripMenuItem loadImageToolStripMenuItem;
        private System.Windows.Forms.Label minLife;
        private System.Windows.Forms.NumericUpDown maxLifeNum;
        private System.Windows.Forms.NumericUpDown minLifeNum;
        private System.Windows.Forms.Label maxLife;
        private System.Windows.Forms.NumericUpDown spawnRateNum;
        private System.Windows.Forms.Label spawnR;
    }
}

