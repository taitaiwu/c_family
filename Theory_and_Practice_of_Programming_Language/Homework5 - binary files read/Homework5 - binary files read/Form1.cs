using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework5___binary_files_read
{
    public partial class Form1 : Form
    {
        TextBox[,] board = new TextBox[6, 6];
        int[,] arr = new int[6, 6];
        int[,] max = new int[6, 6];
        int total = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            board[0, 0] = textBox1;
            board[0, 1] = textBox2;
            board[0, 2] = textBox3;
            board[0, 3] = textBox4;
            board[0, 4] = textBox5;
            board[0, 5] = textBox6;
            board[1, 0] = textBox12;
            board[1, 1] = textBox11;
            board[1, 2] = textBox10;
            board[1, 3] = textBox9;
            board[1, 4] = textBox8;
            board[1, 5] = textBox7;
            board[2, 0] = textBox18;
            board[2, 1] = textBox17;
            board[2, 2] = textBox16;
            board[2, 3] = textBox15;
            board[2, 4] = textBox14;
            board[2, 5] = textBox13;
            board[3, 0] = textBox24;
            board[3, 1] = textBox23;
            board[3, 2] = textBox22;
            board[3, 3] = textBox21;
            board[3, 4] = textBox20;
            board[3, 5] = textBox19;
            board[4, 0] = textBox30;
            board[4, 1] = textBox29;
            board[4, 2] = textBox28;
            board[4, 3] = textBox27;
            board[4, 4] = textBox26;
            board[4, 5] = textBox25;
            board[5, 0] = textBox36;
            board[5, 1] = textBox35;
            board[5, 2] = textBox34;
            board[5, 3] = textBox33;
            board[5, 4] = textBox32;
            board[5, 5] = textBox31;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            int[,] dp = new int[6, 6];
            int[,] path = new int[6, 6]; 

            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    arr[i, j] = int.Parse(board[i, j].Text);
                }
            }

            dp[0, 0] = arr[0, 0];
            for (int i = 1; i < 6; i++) dp[i, 0] = dp[i - 1, 0] + arr[i, 0];  
            for (int j = 1; j < 6; j++) dp[0, j] = dp[0, j - 1] + arr[0, j];  

            for (int i = 1; i < 6; i++)
            {
                for (int j = 1; j < 6; j++)
                {
                    if (dp[i - 1, j] > dp[i, j - 1]) 
                    {
                        dp[i, j] = dp[i - 1, j] + arr[i, j];
                        path[i, j] = 1;  
                    }
                    else 
                    {
                        dp[i, j] = dp[i, j - 1] + arr[i, j];
                        path[i, j] = 0; 
                    }
                }
            }

            int x = 5, y = 5;
            while (x > 0 || y > 0)
            {
                max[x, y] = 1;
                if (path[x, y] == 1) x--; 
                else y--; 
            }
            max[0, 0] = 1; 

            int total = 0;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (max[i, j] != 0)
                    {
                        board[i, j].ForeColor = Color.Red;
                        total += arr[i, j];
                    }
                }
            }
            board[0,0].ForeColor = Color.Red;
            textBox37.Text = total.ToString();
        }


        private void button2_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "二元檔案(*.dat)|*.dat";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                FileStream fs = new FileStream(saveFileDialog1.FileName, FileMode.Create);
                BinaryWriter bw = new BinaryWriter(fs);
                for (int i = 0; i < 6; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (max[i, j] != 0)
                        {
                            bw.Write(max[i, j]);
                            bw.Write(" ");
                        }
                    }
                }

                bw.Flush();
                bw.Close();
                fs.Close();
            }
            
        }
        private void button3_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "二元檔案(*.dat)|*.dat";
            if (openFileDialog1.ShowDialog() == DialogResult.OK )
            {
                FileStream fs = new FileStream(openFileDialog1.FileName, FileMode.Open);
                BinaryReader br = new BinaryReader(fs);

                while (br.PeekChar() >= 0)
                {
                    for (int i = 0; i < 6; i++)
                    {
                        for (int j = 0; j < 6; j++)
                        {
                            board[i, j].Text = br.ReadString();
                        }
                    }
                }

                br.Close();
                fs.Close();
            }
        }

        private void textBox19_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
