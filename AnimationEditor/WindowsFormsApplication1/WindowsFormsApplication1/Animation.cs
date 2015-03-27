using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace WindowsFormsApplication1
{
    class Animation
    {
       public List<Frames> m_Frames;
       public string name;
       public override string ToString()
       {
           return name;
       }
    }
}
