namespace Particle_Editor
{
    partial class ColorDialog
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
            this.okButton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.alphaNum = new System.Windows.Forms.NumericUpDown();
            this.alphaLabel = new System.Windows.Forms.Label();
            this.redLabel = new System.Windows.Forms.Label();
            this.redNum = new System.Windows.Forms.NumericUpDown();
            this.blueLabel = new System.Windows.Forms.Label();
            this.blueNum = new System.Windows.Forms.NumericUpDown();
            this.greenLabel = new System.Windows.Forms.Label();
            this.greenNum = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.alphaNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.redNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenNum)).BeginInit();
            this.SuspendLayout();
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(35, 153);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(75, 23);
            this.okButton.TabIndex = 0;
            this.okButton.Text = "OK";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.Location = new System.Drawing.Point(132, 153);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(75, 23);
            this.cancelButton.TabIndex = 1;
            this.cancelButton.Text = "Cancel";
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // alphaNum
            // 
            this.alphaNum.Location = new System.Drawing.Point(97, 12);
            this.alphaNum.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.alphaNum.Name = "alphaNum";
            this.alphaNum.Size = new System.Drawing.Size(120, 22);
            this.alphaNum.TabIndex = 2;
            // 
            // alphaLabel
            // 
            this.alphaLabel.AutoSize = true;
            this.alphaLabel.Location = new System.Drawing.Point(32, 14);
            this.alphaLabel.Name = "alphaLabel";
            this.alphaLabel.Size = new System.Drawing.Size(44, 17);
            this.alphaLabel.TabIndex = 3;
            this.alphaLabel.Text = "Alpha";
            // 
            // redLabel
            // 
            this.redLabel.AutoSize = true;
            this.redLabel.Location = new System.Drawing.Point(32, 42);
            this.redLabel.Name = "redLabel";
            this.redLabel.Size = new System.Drawing.Size(34, 17);
            this.redLabel.TabIndex = 5;
            this.redLabel.Text = "Red";
            // 
            // redNum
            // 
            this.redNum.Location = new System.Drawing.Point(97, 40);
            this.redNum.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.redNum.Name = "redNum";
            this.redNum.Size = new System.Drawing.Size(120, 22);
            this.redNum.TabIndex = 4;
            // 
            // blueLabel
            // 
            this.blueLabel.AutoSize = true;
            this.blueLabel.Location = new System.Drawing.Point(32, 98);
            this.blueLabel.Name = "blueLabel";
            this.blueLabel.Size = new System.Drawing.Size(36, 17);
            this.blueLabel.TabIndex = 7;
            this.blueLabel.Text = "Blue";
            // 
            // blueNum
            // 
            this.blueNum.Location = new System.Drawing.Point(97, 96);
            this.blueNum.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.blueNum.Name = "blueNum";
            this.blueNum.Size = new System.Drawing.Size(120, 22);
            this.blueNum.TabIndex = 6;
            // 
            // greenLabel
            // 
            this.greenLabel.AutoSize = true;
            this.greenLabel.Location = new System.Drawing.Point(32, 70);
            this.greenLabel.Name = "greenLabel";
            this.greenLabel.Size = new System.Drawing.Size(48, 17);
            this.greenLabel.TabIndex = 9;
            this.greenLabel.Text = "Green";
            // 
            // greenNum
            // 
            this.greenNum.Location = new System.Drawing.Point(97, 68);
            this.greenNum.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.greenNum.Name = "greenNum";
            this.greenNum.Size = new System.Drawing.Size(120, 22);
            this.greenNum.TabIndex = 8;
            // 
            // ColorDialog
            // 
            this.AcceptButton = this.okButton;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.cancelButton;
            this.ClientSize = new System.Drawing.Size(245, 198);
            this.Controls.Add(this.greenLabel);
            this.Controls.Add(this.greenNum);
            this.Controls.Add(this.blueLabel);
            this.Controls.Add(this.blueNum);
            this.Controls.Add(this.redLabel);
            this.Controls.Add(this.redNum);
            this.Controls.Add(this.alphaLabel);
            this.Controls.Add(this.alphaNum);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.okButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ColorDialog";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "ColorDialog";
            ((System.ComponentModel.ISupportInitialize)(this.alphaNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.redNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenNum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button cancelButton;
        private System.Windows.Forms.NumericUpDown alphaNum;
        private System.Windows.Forms.Label alphaLabel;
        private System.Windows.Forms.Label redLabel;
        private System.Windows.Forms.NumericUpDown redNum;
        private System.Windows.Forms.Label blueLabel;
        private System.Windows.Forms.NumericUpDown blueNum;
        private System.Windows.Forms.Label greenLabel;
        private System.Windows.Forms.NumericUpDown greenNum;
    }
}