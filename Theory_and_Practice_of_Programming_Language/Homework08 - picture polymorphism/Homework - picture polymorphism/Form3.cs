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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        public void getData(out string newName, out string container, out double length, out double width)
        {
            newName = textBox1.Text;
            container = textBox2.Text;
            length = double.Parse(textBox3.Text);
            width = double.Parse(textBox4.Text);
        }
    }
}
