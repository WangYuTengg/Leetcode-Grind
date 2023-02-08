class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        flag = 0
        while(flag < len(students)):
            if (students[0] == sandwiches[0]):
                students.pop(0)
                sandwiches.pop(0)
                flag = 0
            else:
                students.append(students[0])
                students.pop(0)
                flag += 1

        return len(students)