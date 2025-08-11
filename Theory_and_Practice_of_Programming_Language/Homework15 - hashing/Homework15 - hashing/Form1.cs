using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework15___hashing
{
    public partial class Form1 : Form
    {
        List<string>[] tables = new List<string>[13];
        TextBox[] arr = new TextBox[13];

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            tables[0] = new List<string>();
            tables[1] = new List<string>();
            tables[2] = new List<string>();
            tables[3] = new List<string>();
            tables[4] = new List<string>();
            tables[5] = new List<string>();
            tables[6] = new List<string>();
            tables[7] = new List<string>();
            tables[8] = new List<string>();
            tables[9] = new List<string>();
            tables[10] = new List<string>();
            tables[11] = new List<string>();
            tables[12] = new List<string>();

            arr[0] = textBox4;
            arr[1] = textBox5;
            arr[2] = textBox6;
            arr[3] = textBox7;
            arr[4] = textBox8;
            arr[5] = textBox9;
            arr[6] = textBox10;
            arr[7] = textBox11;
            arr[8] = textBox12;
            arr[9] = textBox13;
            arr[10] = textBox14;
            arr[11] = textBox15;
            arr[12] = textBox16;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string str1 = textBox1.Text;
                string fold;
                int total;
                bool found;

                seachHash(str1, out fold, out total, out found);

                textBox2.Text = fold;
                textBox3.Text = total.ToString() + " % 13 = " + (total % 13).ToString();

                if (found) throw new Exception("受權碼" + str1 + "重複");
                else tables[total % 13].Add(str1);
                printHash();

            }

            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string str1 = textBox1.Text;
                string fold;
                int total;
                bool found;

                seachHash(str1, out fold, out total, out found);

                textBox2.Text = fold;
                textBox3.Text = total.ToString() + " % 13 = " + (total % 13).ToString();

                if (!found) throw new Exception("受權碼" + str1 + "不存在");
                else tables[total % 13].Remove(str1);
                printHash();

            }

            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                string str1 = textBox1.Text;
                string fold;
                int total;
                bool found;

                seachHash(str1, out fold, out total, out found);

                textBox2.Text = fold;
                textBox3.Text = total.ToString() + " % 13 = " + (total % 13).ToString();

                if (found) MessageBox.Show("受權碼" + str1 + "正確");
                else throw new Exception("受權碼" + str1 + "不存在");

            }

            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        void seachHash(string s, out string fold, out int total, out bool found)
        {
            string[] array;
            string str1 = s;
            fold = "";
            total = 0;
            found = false;

            for (int i = 0; i < s.Length; i += 4)
            {
                s = s.Insert(i, " ");
            }

            array = s.Split(' ');

            for (int i = 0; i < array.Length; i += 2)
            {
                array[i] = new string(array[i].Reverse().ToArray());
            }

            for (int i = 1; i < array.Length; i++)
            {
                fold += array[i];
                total += int.Parse(array[i]);
            }

            for (int i = 0; i < tables[total % 13].Count; i++)
            {
                if (tables[total % 13][i] == str1)
                {
                    found = true;
                    break;
                }
            }

        }

        public void printHash()
        {
            for (int i = 0; i < 13; i++)
            {
                arr[i].Text = "";
            }

            for (int i = 0; i < 13; i++)
            {
                for (int j = 0; j < tables[i].Count; j++)
                {
                    arr[i].Text += " -> " + tables[i][j];
                }
            }
        }
    }
}
