using System;
using CsvHelper;
using System.IO;
using System.Globalization;
using System.Linq;

namespace AdventCode_1_2022
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 3.14;
            int b = Convert.ToInt32(a)
            using (var streamReader =
                   new StreamReader(@"/home/luhyxi/Codeee/Rabiskos/C# Number 2 Now/AdventCode12022/adventofcode.csv"))
            {
                using (var csvReader = new CsvReader(streamReader,CultureInfo.InvariantCulture))
                {
                    var records = csvReader.GetRecords<dynamic>().ToList();
                }
            }
        }
    }
}