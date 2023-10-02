using System;
using CsvHelper;
using CsvHelper.Configuration;
using System.IO;
using System.Globalization;
using System.Linq;
using System.Collections.Generic; // Add this for List

namespace AdventCode_1_2022
{
    public class CsvRecord
    {
        public int Calories { get; set; }
        public bool IsEmpty { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<int> sums = new List<int>(); // Moved the 'sums' list declaration outside the CsvReader scope.

            using (var streamReader = new StreamReader(@"/home/luhyxi/Codeee/Rabiskos/C# Number 2 Now/AdventCode12022/adventofcode.csv"))
            using (var csvReader = new CsvReader(streamReader, new CsvConfiguration(CultureInfo.InvariantCulture)
            {
                HasHeaderRecord = false,// Indicates that the CSV file doesn't have a header row.
                MissingFieldFound = null // Ignore missing fields
            }))
            {
                var records = csvReader.GetRecords<CsvRecord>().ToList();

                foreach (var record in records)
                {
                    if (record.Calories == null) // You can adjust this condition as needed.
                    {
                        record.IsEmpty = true;
                    }
                }

                int currentSum = 0;

                foreach (var record in records)
                {
                    if (record.IsEmpty)
                    {
                        if (currentSum > 0)
                        {
                            sums.Add(currentSum);
                        }
                        currentSum = 0;
                    }
                    else
                    {
                        currentSum += record.Calories;
                    }
                }

                if (currentSum > 0)
                {
                    sums.Add(currentSum);
                }
            }

            // At this point, 'sums' contains the sums of data between rows with no data.
            // You can use 'sums' as needed.
        }
    }
}
