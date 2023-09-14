class Solution(object):
    def countAndSay(self, n):
        sequence = str(n)
        result = []
        count = 1

        for i in range(1, len(sequence)):
            if sequence[i] == sequence[i - 1]:
                count += 1
            else:
                result.append(str(count) + sequence[i - 1])
                count = 1

        result.append(str(count) + sequence[-1])

        return int(''.join(result))
