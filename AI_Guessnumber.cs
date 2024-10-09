/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using System;

namespace HW1
{
    interface Play
    {
        int next(int min, int max);
    }

    abstract class Player : Play
    {
        public string Name { get; set; }
        public abstract int next(int min, int max);
    }

    class NaiveAI : Player
    {
        public override int next(int min, int max)
        {
            return new Random().Next(min, max + 1);
        }
    }

    class BinarySearchAI : NaiveAI
    {
        public override int next(int min, int max)
        {
            return (min + max) / 2;
        }
    }

    class SuperAI : NaiveAI
    {
        public override int next(int min, int max)
        {
            return min;
        }
    }

    class HumanPlayer : Player
    {
        public override int next(int min, int max)
        {
            return int.Parse(Console.ReadLine());
        }
    }

    class Game
    {
        Player player;
        int s, min = 0, max = 99;
        public Game(Player player)
        {
            this.player = player;
            Random rng = new Random();
            s = rng.Next(100);
        }
        public void run()
        {
            while (true)
            {
                Console.WriteLine("({0},{1})", min, max);
                int g = player.next(min, max);
                Console.WriteLine("{0}", g);

                if (g > max || g < min)
                {
                    Console.WriteLine("Out of range. Try again.");
                    continue;
                }
                if (g == s)
                {
                    Console.WriteLine("Bingo.");
                    break;
                }
                else if (g > s)
                {
                    Console.WriteLine("Too large.");
                    max = g - 1;
                }
                else
                {
                    Console.WriteLine("Too small.");
                    min = g + 1;
                }
                if (min > max)
                {
                    Console.WriteLine("Game over.");
                    break;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            new Game(new NaiveAI()).run();
        }
    }
}