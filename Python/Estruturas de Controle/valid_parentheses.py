class Solution(object):
    def isValid(self, s):
        balance = 0
        brackets = {')': -1, '}': -2, ']': -3, '(': 1, '{': 2, '[': 3}
        brackets_i = {'(':')', '[':']', '(':')'}
        
        for index, char in enumerate(s):
            if s[index + 1] != char(brackets_i.values):
                return False
            if char in brackets:
                balance += brackets[char]
        
        return balance == 0