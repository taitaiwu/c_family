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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        public void getData(out string newName, out string container, out double tbase, out double height)
        {
            newName = textBox1.Text;
            container = textBox2.Text;
            tbase = double.Parse(textBox3.Text);
            height = double.Parse(textBox4.Text);
        }
    }
}
