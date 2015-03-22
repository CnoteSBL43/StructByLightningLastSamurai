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
    public partial class ColorDialog : Form
    {
        public event EventHandler ColorDialogOK_Click;

        public ColorDialog()
        {
            InitializeComponent();
        }

        public int AlphaNum
        {
            get { return (int)alphaNum.Value; }

            set{ alphaNum.Value = value; }
        }

        public int RedNum
        {
            get { return (int)redNum.Value; }

            set { redNum.Value = value; }
        }

        public int GreenNum
        {
            get { return (int)greenNum.Value; }

            set { greenNum.Value = value; }
        }

        public int BlueNum
        {
            get { return (int)blueNum.Value; }

            set { blueNum.Value = value; }
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            if(ColorDialogOK_Click != null)
            {
                ColorDialogOK_Click(this, EventArgs.Empty);
            }
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }
}
