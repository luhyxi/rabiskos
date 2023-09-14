namespace Rabiskos_C_;

public class Solution
{
    public int NumberOfEmployeesWhoMetTarget(int[] hours, int target)
    {
        var result = Array.FindAll(hours, element => element >= target);
        return result.Length;
    } 
}
