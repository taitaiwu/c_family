using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework7___recursive
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str1 = textBox1.Text;
            List<string> permutations = Recursive(str1);
            textBox3.Text = string.Join(",", permutations);
            textBox2.Text = fib(str1.Length).ToString();
        }

        private List<string> Recursive(string str)
        {
            List<string> results = new List<string>();
            Recurse("", str, results);
            return results;
        }

        private void Recurse(string prefix, string remaining, List<string> results)
        {
            if (remaining.Length == 0)
            {
                results.Add(prefix);
                return;
            }

            for (int i = 0; i < remaining.Length; i++)
            {
                string newPrefix = prefix + remaining[i];
                string newRemaining = remaining.Substring(0, i) + remaining.Substring(i + 1);
                Recurse(newPrefix, newRemaining, results);
            }
        }

        private int fib(int n)
        {
            if (n == 0)
            {
                return(1);
            }

            else
            {
                return (n * fib(n - 1));
            }
        }
    }
}
