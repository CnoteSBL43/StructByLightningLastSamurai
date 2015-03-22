using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Particle_Editor
{
    static class Program
    {
        
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
           // Application.Run(new ParticleEditor());

            ParticleEditor particleEditor = new ParticleEditor();
            particleEditor.Initialize();
            particleEditor.Show();

            while(particleEditor.Running)
            {
                particleEditor.Update();
                particleEditor.Render();
                Application.DoEvents();

            }

            particleEditor.Terminate();
        }
    }
}
