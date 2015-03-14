using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
namespace WindowsFormsApplication1
{
    class Frames
    {
        public string name;
        Rectangle framerect;
        Rectangle collisionrect;
        Rectangle anchorpt;

        public Rectangle Anchorpt
        {
            get { return anchorpt; }
            set { anchorpt = value; }
        }

        public Rectangle Collisionrect
        {
            get { return collisionrect; }
            set { collisionrect = value; }
        }

        public Rectangle Framerect
        {
            get { return framerect; }
            set { framerect = value; }
        }


    }
}
