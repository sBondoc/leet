def min_diff(arr : list[int]) -> list[list[int]]:
	result = []
	arr.sort()
	minimum = abs(arr[1] - arr[0])
	for i in range(2, len(arr)):
		if abs(arr[i] - arr[i - 1]) < minimum:
			minimum = abs(arr[i] - arr[i - 1])
	for i in range(1, len(arr)):
		if abs(arr[i] - arr[i - 1]) == minimum:
			add = [arr[i], arr[i - 1]]
			add.sort()
			result.append(add)
	result.sort()
	return result

def main():
	arr = [3, 8, -10, 23, 19, -4, -14, 27] 
	print(min_diff(arr))

if __name__ == "__main__":
	main()
