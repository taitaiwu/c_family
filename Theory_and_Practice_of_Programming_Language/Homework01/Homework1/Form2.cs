﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework1
{
    public partial class Form2 : Form
    {
        public Form1 preForm;

        public Form2()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked) button1.Enabled = true;
            else  button1.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form3 f = new Form3();
            f.preFrom = this;
            f.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.preForm.Show();
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.preForm.Close();
            this.Close();
        }
    }
}
