import sys
original = sys.argv[1]
comparison = sys.argv[2]
target = len(original)
progress = 0

for x in range(0, len(original)):
	if x <= len(comparison)-1:
		break;
	elif original[x] == comparison[x]:
		progress += 1
	elif ((original[x] == comparison[x-1]) and (x != 0)) or ((original[x] == comparison[x+1]) and (x != len(comparison)-1)):
		progression += 0.5

percentage = (progress/target) * 100
print("Similarity: {}/{} characters ({}%)".format(progress, target, percentage))