using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Homework3___Tic_Tac_Toe
{
    public partial class Form1 : Form
    {
        public Button[,] board = new Button[3, 3];
        public int[,] state = new int[3, 3];
        public bool start = false;
        public bool computer = true;
        public int counter = 0;

        public Form1()
        {
            InitializeComponent();
            radioButton1.Checked = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            board[0, 0] = button1;
            board[0, 1] = button2;
            board[0, 2] = button3;
            board[1, 0] = button4;
            board[1, 1] = button5;
            board[1, 2] = button6;
            board[2, 0] = button7;
            board[2, 1] = button8;
            board[2, 2] = button9;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    state[i, j] = 0;
                }
            }

            counter = 0;
            showBoard();
            start = true;

            if (radioButton2.Checked)
            {
                computer = false;
                textBox1.Text = "玩家";
            }

            else
            {
                computer = true;
                textBox1.Text = "電腦";
                play();
            }
        }

        private void play()
        {
            counter++;
            //rule1~2 : computer last1 or user last1
            if ((state[0, 0] + state[1, 1] + state[2, 2] == 2) || (state[0, 0] + state[1, 1] + state[2, 2] == 20))
            {
                for (int i = 0; i < 3; i++)
                {
                    if (state[i, i] == 0) 
                    {
                        state[i, i] = 1; 
                        computer = false;
                        showBoard();
                        return;
                    }
                }
            }

            else if ((state[0, 2] + state[1, 1] + state[2, 0] == 2) || (state[0, 2] + state[1, 1] + state[2, 0] == 20))
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 2; j >= 0; j--)
                    {
                        if (state[i, j] ==0) 
                        {
                            state[i, j] = 1;
                            computer = false;
                            showBoard();
                            return;
                        }
                    }
                }
            }

            for (int i = 0; i < 3; i++)
            {
                if (state[i, 0] + state[i, 1] + state[i, 2] == 2)
                {
                    for (int j = 0; j <3; j++)
                    {
                        if (state[i, j] == 0)
                        {
                            state[i, j] = 1;
                            computer = false;
                            showBoard();
                            return;
                        }
                    }
                }

                else if (state[0, i] + state[1, i] + state[2, i] == 2)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (state[j, i] == 0)
                        {
                            state[j, i] = 1;
                            computer = false;
                            showBoard();
                            return;
                        }
                    }
                }
            }

            for (int i = 0; i < 3; i++)
            {
                if (state[i, 0] + state[i, 1] + state[i, 2] == 20)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (state[i, j] == 0)
                        {
                            state[i, j] = 1;
                            computer = false;
                            showBoard();
                            return;
                        }
                    }
                }

                else if (state[0, i] + state[1, i] + state[2, i] == 20)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (state[j, i] == 0)
                        {
                            state[j, i] = 1;
                            computer = false;
                            showBoard();
                            return;
                        }
                    }
                }
            }

            //rule3~4
            int n;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0;j < 3; j++)
                {
                    if (state[i, j] == 0)
                    {
                        state[i, j] = 1;
                        n = 0;

                        if (state[0, 0] + state[1, 1] + state[2, 2] == 2) n++;
                        if (state[0, 2] + state[1, 1] + state[2, 0] == 2) n++;

                        for (int k = 0; k < 3; k++)
                        {
                            if (state[0, k] + state[1, k] + state[2, k] == 2) n++;
                            if (state[k, 0] + state[k, 1] + state[k, 2] == 2) n++;
                        }

                        if (n >= 2)
                        {
                            showBoard();
                            computer = false;
                            return;
                        }
                        else state[i, j] = 0;
                    }
                }
            }

            if (((state[0, 0] + state[1, 1] + state[2, 1] == 21) && (state[0, 2] + state[1, 1] + state[2, 0] == 1)) || ((state[0, 0] + state[1, 1] + state[2, 1] == 1) && (state[0, 2] + state[1, 1] + state[2, 0] == 21)))
                {
                state[0, 1] = 1;
                showBoard();
                computer = false;
                return;
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (state[i, j] == 0)
                    {
                        state[i, j] = 10;
                        n = 0;

                        if (state[0, 0] + state[1, 1] + state[2, 2] == 20) n++;
                        if (state[0, 2] + state[1, 1] + state[2, 0] == 20) n++;

                        for (int k = 0; k < 3; k++)
                        {
                            if (state[0, k] + state[1, k] + state[2, k] == 20) n++;
                            if (state[k, 0] + state[k, 1] + state[k, 2] == 20) n++;
                        }

                        if (n >= 2)
                        {
                            showBoard();
                            computer = false;
                            return;
                        }
                        else state[i, j] = 0;
                    }
                }
            }

            //rule5~7
            if (state[1, 1] == 0)
            {
                state[1, 1] = 1;
                showBoard();
                computer = false;
                return;
            }
            
            for (int i = 0; i < 3; i+=2)
            {
                for (int j = 0; j < 3; j+=2)
                {
                    if (state[i, j] == 0)
                    {
                        state[i, j] = 1;
                        showBoard();
                        computer = false;
                        return;
                    }
                }
            }

            for (int i = 0; i < 3; i ++)
            {
                for (int j = 0; j < 3; j ++)
                {
                    if (state[i, j] == 0)
                    {
                        state[i, j] = 1;
                        showBoard();
                        computer = false;
                        return;
                    }
                }
            }
        }

        private void showBoard()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (state[i, j] == 0) board[i, j].Text = "";
                    if (state[i, j] == 1) board[i, j].Text = "O";
                    if (state[i, j] == 10) board[i, j].Text = "X";
                }
            }

            if (computer) textBox1.Text = "電腦";
            else textBox1.Text = "玩家";

            if ((state[0, 0] + state[1, 1] + state[2, 2] == 3) || (state[0, 2] + state[1, 1] + state[2, 0] == 3))
            {
                MessageBox.Show("電腦獲勝", "遊戲結束", MessageBoxButtons.OK, MessageBoxIcon.Information);
                start = false;
                return;
            }

            for (int i = 0; i <3 ; i++)
            {
                if ((state[i, 0] + state[i, 1] + state[i, 2] == 3) || (state[0, i] + state[1, i] + state[2, i] == 3))
                {
                    MessageBox.Show("電腦獲勝", "遊戲結束", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    start = false;
                    return;
                }
            }

            if ((state[0, 0] + state[1, 1] + state[2, 2] == 30) || (state[0, 2] + state[1, 1] + state[2, 0] == 30))
            {
                MessageBox.Show("恭喜玩家獲勝", "遊戲結束", MessageBoxButtons.OK, MessageBoxIcon.Information);
                start = false;

                return;

            }

            for (int i = 0; i < 3; i++)
            {
                if ((state[i, 0] + state[i, 1] + state[i, 2] == 30) || (state[0, i] + state[1, i] + state[2, i] == 30))
                {
                    MessageBox.Show("恭喜玩家獲勝", "遊戲結束", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    start = false;
                    return;
                }
            }

            if (counter == 9)
            {
                MessageBox.Show("雙方平手", "遊戲結束", MessageBoxButtons.OK, MessageBoxIcon.Information);
                start = false;
                return;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[0, 0] == 0)
            {
                state[0, 0] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[0, 1] == 0)
            {
                state[0, 1] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[0, 2] == 0)
            {
                state[0, 2] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[1, 0] == 0)
            {
                state[1, 0] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[1, 1] == 0)
            {
                state[1, 1] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[1, 2] == 0)
            {
                state[1, 2] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[2, 0] == 0)
            {
                state[2, 0] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[2, 1] == 0)
            {
                state[2, 1] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (start && !computer && state[2, 2] == 0)
            {
                state[2, 2] = 10;
                counter++;
                computer = true;
                showBoard();
                play();
            }
        }
    }
}
