using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Homework9___maze
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        TextBox[,] board = new TextBox[7, 7];

        private void Form1_Load(object sender, EventArgs e)
        {
            board[0, 0] = textBox1;
            board[0, 1] = textBox2;
            board[0, 2] = textBox3;
            board[0, 3] = textBox4;
            board[0, 4] = textBox5;
            board[0, 5] = textBox6;
            board[0, 6] = textBox7;
            board[1, 0] = textBox8;
            board[1, 1] = textBox9;
            board[1, 2] = textBox10;
            board[1, 3] = textBox11;
            board[1, 4] = textBox12;
            board[1, 5] = textBox13;
            board[1, 6] = textBox14;
            board[2, 0] = textBox15;
            board[2, 1] = textBox16;
            board[2, 2] = textBox17;
            board[2, 3] = textBox18;
            board[2, 4] = textBox19;
            board[2, 5] = textBox20;
            board[2, 6] = textBox21;
            board[3, 0] = textBox22;
            board[3, 1] = textBox23;
            board[3, 2] = textBox24;
            board[3, 3] = textBox25;
            board[3, 4] = textBox26;
            board[3, 5] = textBox27;
            board[3, 6] = textBox28;
            board[4, 0] = textBox29;
            board[4, 1] = textBox30;
            board[4, 2] = textBox31;
            board[4, 3] = textBox32;
            board[4, 4] = textBox33;
            board[4, 5] = textBox34;
            board[4, 6] = textBox35;
            board[5, 0] = textBox36;
            board[5, 1] = textBox37;
            board[5, 2] = textBox38;
            board[5, 3] = textBox39;
            board[5, 4] = textBox40;
            board[5, 5] = textBox41;
            board[5, 6] = textBox42;
            board[6, 0] = textBox43;
            board[6, 1] = textBox44;
            board[6, 2] = textBox45;
            board[6, 3] = textBox46;
            board[6, 4] = textBox47;
            board[6, 5] = textBox48;
            board[6, 6] = textBox49;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "二元檔案(*.dat)|*.dat";

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                FileStream fs = new FileStream(saveFileDialog1.FileName, FileMode.Create);
                BinaryWriter bw = new BinaryWriter(fs);

                for (int i=0; i<7; i++)
                {
                    for (int j=0; j<7; j++)
                    {
                        bw.Write(board[i, j].Text);
                    }
                }

                bw.Flush();
                bw.Close();
                fs.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "二元檔案(*.dat)|*.dat";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                FileStream fs = new FileStream(openFileDialog1.FileName, FileMode.Open);
                BinaryReader br = new BinaryReader(fs);

                for (int i = 0; i < 7; i++)
                {
                    for (int j = 0; j < 7; j++)
                    {
                        board[i, j].Text = br.ReadString();
                        board[i, j].ForeColor = Color.Black;
                    }
                }

                br.Close();
                fs.Close();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int x = 0, y = 0;
            MyStack myStack = new MyStack();

            while (true)
            {
                board[x, y].Text = "1";
                board[x, y].ForeColor = Color.Red;

                if (x == 6 && y == 6) break;

                if (x + 1 < board.GetLength(0) && board[x + 1, y].Text == "0")
                {
                    myStack.push(x, y);
                    x++;
                }
                else if (y + 1 < board.GetLength(1) && board[x, y + 1].Text == "0")
                {
                    myStack.push(x, y);
                    y++;
                }
                else if (x - 1 >= 0 && board[x - 1, y].Text == "0")
                {
                    myStack.push(x, y);
                    x--;
                }
                else if (y - 1 >= 0 && board[x, y - 1].Text == "0")
                {
                    myStack.push(x, y);
                    y--;
                }

                else
                {
                    board[x, y].Text = "2";
                    board[x, y].ForeColor = Color.Black;

                    myStack.pop(out x, out y);
                }
            }

            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (board[i, j].Text == "0")
                    {
                        board[i, j].Text = "2";
                        board[i, j].ForeColor = Color.Black;
                    }
                }
            }
        }
    }

    class MyStack
    {
        const int MAX = 50;
        int[,] stack = new int[MAX, 2];
        int top = -1;

        public void push(int x, int y)
        {
            top++;
            stack[top, 0] = x;
            stack[top, 1] = y;
        }

        public void pop (out int x, out int y)
        {
            x = stack[top, 0];
            y = stack[top, 1];
            top--;
        }
    }
}
