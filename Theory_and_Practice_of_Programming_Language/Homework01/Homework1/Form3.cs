using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework1
{
    public partial class Form3 : Form
    {
        public Form2 preFrom;
        public int total = 0;
        public int temp1 = 0;
        public int temp2 = 0;

        public Form3()
        {
            InitializeComponent();
            textBox1.Text = total.ToString();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked) total += 69;
            else total -= 69;
            textBox1.Text = total.ToString();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked) total += 49;
            else total -= 49;
            textBox1.Text = total.ToString();
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked) total += 59;
            else total -= 59;
            textBox1.Text = total.ToString();
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked) total += 79;
            else total -= 79;
            textBox1.Text = total.ToString();
        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {
            total -= temp1;
            temp1 = 0;

            if (checkBox5.Checked)
            {
                radioButton1.Enabled = radioButton2.Enabled = true;

                if (radioButton1.Checked == radioButton2.Checked == false)
                {
                    if (radioButton1.Checked) temp1 = 35;

                    else if (radioButton2.Checked) temp1 = 25;
                }

            }

            else
            {
                radioButton1.Enabled = radioButton2.Enabled = false;
                radioButton1.Checked = radioButton2.Checked = false;
                temp1 = 0;
            }


            total += temp1;
            textBox1.Text = total.ToString();
        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            total -= temp2;
            temp2 = 0;

            if (checkBox6.Checked)
            {
                radioButton3.Enabled = radioButton4.Enabled = radioButton5.Enabled = true;

                if (radioButton3.Checked) temp2 = 25;
                else if (radioButton4.Checked) temp2 = 35;
                else if (radioButton5.Checked) temp2 = 45;
            }

            else
            {
                radioButton3.Enabled = radioButton4.Enabled = radioButton5.Enabled = false;
                radioButton3.Checked = radioButton4.Checked = radioButton5.Checked = false;
                temp2 = 0;
            }

            total += temp2;
            textBox1.Text = total.ToString();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.preFrom.Show();
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.preFrom.preForm.Close();
            this.preFrom.Close();
            this.Close();
        }
    }
}
