#include<iostream>
using namespace std;

char cubes[6][3][3];
// [면][가로][세로]
// 0: 위, 1: 아래, 2: 앞, 3: 뒤, 4: 왼, 5: 오른
int n;

void init() {
	for (int face = 0; face < 6; ++face) {
		char color;
		switch (face) {
		case 0 :
			color = 'w';
			break;
		case 1:
			color = 'y';
			break;
		case 2:
			color = 'r';
			break;
		case 3:
			color = 'o';
			break;
		case 4:
			color = 'g';
			break;
		case 5:
			color = 'b';
			break;
		}

		for (int row = 0; row < 3; ++row) {
			for (int col = 0; col < 3; ++col) {
				cubes[face][row][col] = color;
			}
		}
	}
}

void roll_clock(int face, int dir) {
	char temp[3][3] = {};

	if (dir == 1) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				temp[i][j] = cubes[face][2 - j][i];
			}
		}
	}
	else {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				temp[i][j] = cubes[face][j][2 - i];
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubes[face][i][j] = temp[i][j];
		}
	}
}

void roll(char* op) {
	if (op[0] == 'U') {
		if (op[1] == '+') {
			roll_clock(0, 1);
			// 3뒤 -> 5오른 -> 2앞 -> 4왼
			char temp[3] = { cubes[4][0][0], cubes[4][0][1], cubes[4][0][2] };

			cubes[4][0][0] = cubes[2][0][0]; 
			cubes[4][0][1] = cubes[2][0][1]; 
			cubes[4][0][2] = cubes[2][0][2];

			cubes[2][0][0] = cubes[5][0][0]; 
			cubes[2][0][1] = cubes[5][0][1]; 
			cubes[2][0][2] = cubes[5][0][2];

			cubes[5][0][0] = cubes[3][0][0];
			cubes[5][0][1] = cubes[3][0][1];
			cubes[5][0][2] = cubes[3][0][2];

			cubes[3][0][0] = temp[0];
			cubes[3][0][1] = temp[1];
			cubes[3][0][2] = temp[2];
		}
		else if (op[1] == '-') {
			roll_clock(0, -1);
			// 4왼 -> 2앞 -> 5오른 -> 3뒤
			char temp[3] = { cubes[3][0][0], cubes[3][0][1], cubes[3][0][2] };
			
			cubes[3][0][0] = cubes[5][0][0];
			cubes[3][0][1] = cubes[5][0][1];
			cubes[3][0][2] = cubes[5][0][2];

			cubes[5][0][0] = cubes[2][0][0];
			cubes[5][0][1] = cubes[2][0][1];
			cubes[5][0][2] = cubes[2][0][2];

			cubes[2][0][0] = cubes[4][0][0];
			cubes[2][0][1] = cubes[4][0][1];
			cubes[2][0][2] = cubes[4][0][2];

			cubes[4][0][0] = temp[0];
			cubes[4][0][1] = temp[1];
			cubes[4][0][2] = temp[2];
		}
	}
	else if (op[0] == 'D') {
		if (op[1] == '+') {
			roll_clock(1, 1);
			// 3뒤 -> 4왼 -> 2앞 -> 5오른
			char temp[3] = { cubes[5][2][0], cubes[5][2][1], cubes[5][2][2] };

			cubes[5][2][0] = cubes[2][2][0];
			cubes[5][2][1] = cubes[2][2][1];
			cubes[5][2][2] = cubes[2][2][2];

			cubes[2][2][0] = cubes[4][2][0];
			cubes[2][2][1] = cubes[4][2][1];
			cubes[2][2][2] = cubes[4][2][2];

			cubes[4][2][0] = cubes[3][2][0];
			cubes[4][2][1] = cubes[3][2][1];
			cubes[4][2][2] = cubes[3][2][2];

			cubes[3][2][0] = temp[0];
			cubes[3][2][1] = temp[1];
			cubes[3][2][2] = temp[2];
		}
		else if (op[1] == '-') {
			roll_clock(1, -1);
			// 5오른 -> 2앞 -> 4왼 -> 3뒤
			char temp[3] = { cubes[3][2][0], cubes[3][2][1], cubes[3][2][2] };
			
			cubes[3][2][0] = cubes[4][2][0];
			cubes[3][2][1] = cubes[4][2][1];
			cubes[3][2][2] = cubes[4][2][2];

			cubes[4][2][0] = cubes[2][2][0];
			cubes[4][2][1] = cubes[2][2][1];
			cubes[4][2][2] = cubes[2][2][2];

			cubes[2][2][0] = cubes[5][2][0];
			cubes[2][2][1] = cubes[5][2][1];
			cubes[2][2][2] = cubes[5][2][2];

			cubes[5][2][0] = temp[0];
			cubes[5][2][1] = temp[1];
			cubes[5][2][2] = temp[2];
		}
	}
	else if (op[0] == 'F') {
		if (op[1] == '+') {
			roll_clock(2, 1);
			// 0위 -> 5오른 -> 1아래 -> 4왼
			char temp[3] = { cubes[4][2][2], cubes[4][1][2], cubes[4][0][2] };

			cubes[4][0][2] = cubes[1][0][0];
			cubes[4][1][2] = cubes[1][0][1];
			cubes[4][2][2] = cubes[1][0][2];

			cubes[1][0][0] = cubes[5][2][0];
			cubes[1][0][1] = cubes[5][1][0];
			cubes[1][0][2] = cubes[5][0][0];

			cubes[5][0][0] = cubes[0][2][0];
			cubes[5][1][0] = cubes[0][2][1];
			cubes[5][2][0] = cubes[0][2][2];

			cubes[0][2][0] = temp[0];
			cubes[0][2][1] = temp[1];
			cubes[0][2][2] = temp[2];
		}
		else if (op[1] == '-') {
			roll_clock(2, -1);
			// 4왼 -> 1아래 -> 5오른 -> 0위
			char temp[3] = { cubes[0][2][2], cubes[0][2][1], cubes[0][2][0] };

			cubes[0][2][0] = cubes[5][0][0];
			cubes[0][2][1] = cubes[5][1][0];
			cubes[0][2][2] = cubes[5][2][0];

			cubes[5][2][0] = cubes[1][0][0];
			cubes[5][1][0] = cubes[1][0][1];
			cubes[5][0][0] = cubes[1][0][2];

			cubes[1][0][0] = cubes[4][0][2];
			cubes[1][0][1] = cubes[4][1][2];
			cubes[1][0][2] = cubes[4][2][2];

			cubes[4][0][2] = temp[0];
			cubes[4][1][2] = temp[1];
			cubes[4][2][2] = temp[2];
		}
	}
	else if (op[0] == 'B') {
		if (op[1] == '+') {
			roll_clock(3, 1);
			// 0위 -> 4왼 -> 1아래 -> 5오른
			char temp[3] = { cubes[5][0][2], cubes[5][1][2], cubes[5][2][2] };

			cubes[5][0][2] = cubes[1][2][2];
			cubes[5][1][2] = cubes[1][2][1];
			cubes[5][2][2] = cubes[1][2][0];

			cubes[1][2][0] = cubes[4][0][0];
			cubes[1][2][1] = cubes[4][1][0];
			cubes[1][2][2] = cubes[4][2][0];

			cubes[4][0][0] = cubes[0][0][2];
			cubes[4][1][0] = cubes[0][0][1];
			cubes[4][2][0] = cubes[0][0][0];

			cubes[0][0][0] = temp[0];
			cubes[0][0][1] = temp[1];
			cubes[0][0][2] = temp[2];
		}
		else if (op[1] == '-') {
			roll_clock(3, -1);
			// 5오른 -> 1아래 -> 4왼 -> 0위
			char temp[3] = { cubes[0][0][0], cubes[0][0][1], cubes[0][0][2] };

			cubes[0][0][0] = cubes[4][2][0];
			cubes[0][0][1] = cubes[4][1][0];
			cubes[0][0][2] = cubes[4][0][0];

			cubes[4][0][0] = cubes[1][2][0];
			cubes[4][1][0] = cubes[1][2][1];
			cubes[4][2][0] = cubes[1][2][2];

			cubes[1][2][0] = cubes[5][2][2];
			cubes[1][2][1] = cubes[5][1][2];
			cubes[1][2][2] = cubes[5][0][2];

			cubes[5][0][2] = temp[0];
			cubes[5][1][2] = temp[1];
			cubes[5][2][2] = temp[2];
		}
	}
	else if (op[0] == 'L') {
		if (op[1] == '+') {
			roll_clock(4, 1);
			// 0위 -> 2앞 -> 1아래 -> 3뒤
			char temp[3] = { cubes[3][2][2], cubes[3][1][2], cubes[3][0][2] };

			cubes[3][0][2] = cubes[1][2][0];
			cubes[3][1][2] = cubes[1][1][0];
			cubes[3][2][2] = cubes[1][0][0];

			cubes[1][0][0] = cubes[2][0][0];
			cubes[1][1][0] = cubes[2][1][0];
			cubes[1][2][0] = cubes[2][2][0];

			cubes[2][0][0] = cubes[0][0][0];
			cubes[2][1][0] = cubes[0][1][0];
			cubes[2][2][0] = cubes[0][2][0];

			cubes[0][0][0] = temp[0];
			cubes[0][1][0] = temp[1];
			cubes[0][2][0] = temp[2];
		}
		else if (op[1] == '-') {
			roll_clock(4, -1);
			// 3뒤 -> 1아래 -> 2앞 -> 0위
			char temp[3] = { cubes[0][2][0], cubes[0][1][0], cubes[0][0][0] };

			cubes[0][0][0] = cubes[2][0][0];
			cubes[0][1][0] = cubes[2][1][0];
			cubes[0][2][0] = cubes[2][2][0];

			cubes[2][0][0] = cubes[1][0][0];
			cubes[2][1][0] = cubes[1][1][0];
			cubes[2][2][0] = cubes[1][2][0];

			cubes[1][0][0] = cubes[3][2][2];
			cubes[1][1][0] = cubes[3][1][2];
			cubes[1][2][0] = cubes[3][0][2];

			cubes[3][0][2] = temp[0];
			cubes[3][1][2] = temp[1];
			cubes[3][2][2] = temp[2];
		}
	}
	else if (op[0] == 'R') {
		if (op[1] == '+') {
			roll_clock(5, 1);
			// 0위 -> 3뒤 -> 1아래 -> 2앞
			char temp[3] = { cubes[2][0][2], cubes[2][1][2], cubes[2][2][2] };

			cubes[2][0][2] = cubes[1][0][2];
			cubes[2][1][2] = cubes[1][1][2];
			cubes[2][2][2] = cubes[1][2][2];

			cubes[1][0][2] = cubes[3][2][0];
			cubes[1][1][2] = cubes[3][1][0];
			cubes[1][2][2] = cubes[3][0][0];

			cubes[3][0][0] = cubes[0][2][2];
			cubes[3][1][0] = cubes[0][1][2];
			cubes[3][2][0] = cubes[0][0][2];

			cubes[0][0][2] = temp[0];
			cubes[0][1][2] = temp[1];
			cubes[0][2][2] = temp[2];
		}
		else if (op[1] == '-') {
			roll_clock(5, -1);
			// 2앞 -> 1아래 -> 3뒤 -> 0위
			char temp[3] = { cubes[0][0][2], cubes[0][1][2], cubes[0][2][2] };

			cubes[0][0][2] = cubes[3][2][0];
			cubes[0][1][2] = cubes[3][1][0];
			cubes[0][2][2] = cubes[3][0][0];

			cubes[3][0][0] = cubes[1][2][2];
			cubes[3][1][0] = cubes[1][1][2];
			cubes[3][2][0] = cubes[1][0][2];

			cubes[1][0][2] = cubes[2][0][2];
			cubes[1][1][2] = cubes[2][1][2];
			cubes[1][2][2] = cubes[2][2][2];

			cubes[2][0][2] = temp[0];
			cubes[2][1][2] = temp[1];
			cubes[2][2][2] = temp[2];
		}
	}
}

void result() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%c", cubes[0][i][j]);
		}
		printf("\n");
	}
}

void input() {
	scanf("%d", &n);
	while (n--) {
		char op[2010];
		scanf("%s", op);
		roll(op);
	}

	result();
}

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		init();
		input();
	}

	return 0;
}
