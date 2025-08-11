using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework2___calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public decimal temp1 = 0;
        public decimal temp2 = 0;
        public int cal = 0;
        public bool pre = false;
        public bool number = false;
        public bool eql = false;

        private void num_Click(object sender, EventArgs e)
        {
            Button button = sender as Button;

            if (textBox1.Text == "0")
            {
                textBox1.Text = button.Text;
                number = true;
            }
            else if (pre == true && number == false)
            {
                textBox1.Text = button.Text;
                number = true;
            }
            else textBox1.Text += button.Text;
        }

        private void point_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.IndexOf(".") == -1) textBox1.Text += ".";
        }

        private void CLR_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
            eql = false;
            number = false;
            pre = false;
            temp1 = 0;
            temp2 = 0;
            cal = 0;
        }

        private void equal_Click(object sender, EventArgs e)
        {
            decimal result = 0;
            temp2 = decimal.Parse(textBox1.Text);

            if (cal == 1) result = temp1 + temp2;
            else if (cal == 2) result = temp1 - temp2;
            else if (cal == 3) result = temp1 * temp2;
            else if (cal == 4)
            {
                try
                {
                    result = temp1 / temp2;
                }

                catch
                {
                    MessageBox.Show("嘗試以零除", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }

            if (eql == false)
            {
                eql = true;
                temp1 = temp2;
            }

            textBox1.Text = result.ToString();
            number = false;
            pre = false;
        }

        private void cal_Click(object sender, EventArgs e)
        {
            Button button = sender as Button;

            if (pre == false)
            {
                temp1 = decimal.Parse(textBox1.Text);
                pre = true;
                number = false;

                if (button.Text == "+") cal = 1;
                else if (button.Text == "-") cal = 2;
                else if (button.Text == "*") cal = 3;
                else if (button.Text == "/") cal = 4;
            }

            else
            {
                if (cal == 1) temp1 += decimal.Parse(textBox1.Text);
                else if (cal == 2) temp1 -= decimal.Parse(textBox1.Text);
                else if (cal == 3) temp1 *= decimal.Parse(textBox1.Text);
                else if (cal == 4)
                {
                    try
                    {
                        temp1 /= decimal.Parse(textBox1.Text);
                    }

                    catch
                    {
                        MessageBox.Show("嘗試以零除", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }

                    pre = true;
                number = false;

                if (button.Text == "+") cal = 1;
                else if (button.Text == "-") cal = 2;
                else if (button.Text == "*") cal = 3;
                else if (button.Text == "/") cal = 4;
            }

            
        }
    }
}
