def is_2pow(n : int):
	return (n != 0) and ((n & n - 1)== 0)

def main():
	print(is_2pow(2 ** 10))

if __name__ == "__main__":
	main()
