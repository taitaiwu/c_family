using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework___picture_polymorphism
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        public void getData(out string newName, out string container, out double radius)
        {
            newName = textBox1.Text;
            container = textBox2.Text;
            radius = double.Parse(textBox3.Text);
        }
    }
}
