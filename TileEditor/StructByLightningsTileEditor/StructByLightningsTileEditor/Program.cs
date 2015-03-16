using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StructByLightningsTileEditor
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
            //Application.Run(new Form1()); // We do Not Need this anymore

            // Making a new Form so that we can acesess Initilize Render Update etc.
            Form1 NewForm = new Form1();
            // Going to Call NewForm Initialize And NewForm Show that we can Show the Editor on the screen 
            NewForm.Initialize();
            NewForm.Show();
            // Going to make a form loop that will Run forever untill the user exits the Program
            while(NewForm.IsLooping)
            {
                // Going to  Call Update so that if the user needs to update it will happen in this loop
              //  NewForm.Update();
                // Going to call Render SO that we can render all of the things we need to the screen. 
                NewForm.Render();
                // Going to call to Application.DoEvents();
                Application.DoEvents();
            }
            // I am going to Call Terminate so that i can destory all of the things I used in the DirectX Wrappers 
            NewForm.Terminate();
        }
    }
}
