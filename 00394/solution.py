class Solution:		
	def decodeString(self, s : str) -> str:
		pass

def index_pair(s : str, i : int, left : str = "[", right : str = "]") -> int:
	n = i
	depth = 1
	while (0 < depth):
		n += 1
		if (s[n] == left):
			depth += 1
		if (s[n] == right):
			depth -= 1
	return n

def decode(s : str, i : int = 0, left : str = "[", right : str = "]") -> str:
	result = ""
	j = i
	while 0 < len(s):
		pre = ""
		while j < len(s) and not s[j].isdigit():
			pre += s[j]
			j += 1
		if (len(s) <= j):
			result += pre
			break
		int_start = j
		while (s[j] != left):
			j += 1
		n = int(s[int_start : j])
		if (left not in inner(s)) and (right not in inner(s)):
			result += pre + n * inner(s, )
		else:
			result += pre + n * decode(s[j + 1 : index_pair(s, j)])
		j = index_pair(s, j) + 1
		s = s[j :]
		j = 0
	return result

def inner(s : str, i : int = 0, left : str = "[", right : str = "]") -> str:
	j = i
	while (s[j] != left):
		j += 1
	return s[j + 1 : index_pair(s, j, left, right)]
	
def main():
	print(decode(input()))

if  __name__ == "__main__":
	main()
