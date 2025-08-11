using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using static Homework___picture_polymorphism.Form2;

namespace Homework___picture_polymorphism
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Picture g = new Picture("Graph");
        List<Picture> allPicture = new List<Picture>();
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "{Picture Graph : }";
            allPicture.Add(g);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                Form2 f2 = new Form2();
                f2.ShowDialog();
                string newName, container;

                if (f2.DialogResult == DialogResult.OK)
                {
                    f2.getData(out newName, out container);
                    Picture picture = allPicture.Find(p => p.getName() == container);

                    if (picture != null)
                    {
                        Picture newPicture = new Picture(newName);
                        picture.addComponent(newPicture);
                        allPicture.Add(newPicture);
                        textBox1.Text = g.show();
                    }
                    else
                    {
                        MessageBox.Show("不存在的容器 : " + container);
                    }
                }
            }

            catch (Exception ex)
            {
                MessageBox.Show("輸入的字串格式不正確", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                Form3 f3 = new Form3();
                f3.ShowDialog();
                string shapeName, container;
                double length, width;

                if (f3.DialogResult == DialogResult.OK)
                {
                    f3.getData(out shapeName, out container, out length, out width);
                    Picture picture = allPicture.Find(p => p.getName() == container);

                    if (picture != null)
                    {
                        picture.addComponent(new Rectangle(shapeName, length, width));
                        textBox1.Text = g.show();
                    }

                    else
                    {
                        MessageBox.Show("不存在的容器 : " + container);
                    }
                }
            }

            catch (Exception ex)
            {
                MessageBox.Show("輸入的字串格式不正確", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                Form4 f4 = new Form4();
                f4.ShowDialog();
                string shapeName, container;
                double tbase, height;

                if (f4.DialogResult == DialogResult.OK)
                {
                    f4.getData(out shapeName, out container, out tbase, out height);
                    Picture picture = allPicture.Find(p => p.getName() == container);

                    if (picture != null)
                    {
                        picture.addComponent(new Triangle(shapeName, tbase, height));
                        textBox1.Text = g.show();
                    }

                    else
                    {
                        MessageBox.Show("不存在的容器 : " + container);
                    }
                }
            }

            catch (Exception ex)
            {
                MessageBox.Show("輸入的字串格式不正確", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                Form5 f5 = new Form5();
                f5.ShowDialog();
                string shapeName, container;
                double radius;
                if(f5.DialogResult == DialogResult.OK)
{
                    f5.getData(out shapeName, out container, out radius);
                    Picture picture = allPicture.Find(p => p.getName() == container);

                    if (picture != null)
                    {
                        picture.addComponent(new Circle(shapeName, radius));
                        textBox1.Text = g.show();
                    }

                    else
                    {
                        MessageBox.Show("不存在的容器 : " + container);
                    }
                }
            }

            catch (Exception ex)
            {
                MessageBox.Show("輸入的字串格式不正確", "錯誤訊息", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox2.Text = g.area().ToString();
        }
    }

    abstract class Component
    {
        protected string name;
        public abstract double area();
        public abstract string show();
        public string getName()
        {
            return name;
        }
    }

    abstract class Shape : Component { }
    class Rectangle : Shape
    {
        private double length;
        private double width;

        public Rectangle(string n, double l, double w)
        {
            name = n;
            length = l;
            width = w;
        }
        public override double area()
        {
            return length * width;
        }
        public override string show()
        {
            return "Rectangle " + name + "(" + length + "," + width + ")";
        }
    }

    class Circle : Shape
    {
        private double radius;
        public Circle(string n, double r)
        {
            name = n;
            radius = r;
        }
        public override double area()
        {
            return Math.PI * radius * radius;
        }
        public override string show()
        {
            return "Circle " + name + "(" + radius + ")";
        }
    }

    class Triangle : Shape
    {
        private double baseLength;
        private double height;
        public Triangle(string n, double b, double h)
        {
            name = n;
            baseLength = b;
            height = h;
        }
        public override double area()
        {
            return 0.5 * baseLength * height;
        }
        public override string show()
        {
            return "Triangle " + name + "(" + baseLength + "," + height + ")";
        }
    }

    class Picture : Component
    {
        private List<Component> coms = new List<Component>();
        public Picture(string n)
        {
            name = n;
        }

        public void addComponent(Component c)
        {
            coms.Add(c);
        }

        public override double area()
        {
            double total = 0.0;

            for (int i=0; i < coms.Count; i++)
            {
                total += coms[i].area();
            }

            return total;
        }

        public override string show()
        {
            string str = "{Picture " + name + " : ";

            for (int i = 0; i < coms.Count; i++)
            {
                str += " " + coms[i].show();
            }

            str += "}";
            return str;
        }
    }
}
