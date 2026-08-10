#define MAX_N 100001

static bool can_win[MAX_N];
static int computed_up_to;


bool winnerSquareGame(int count) {
    if (count <= computed_up_to) {
        return can_win[count];
    }

    for (int stones = computed_up_to + 1; stones <= count; stones++) {
        can_win[stones] = false;
        for (int root = 1; root * root <= stones; root++) {
            int square = root * root;
            if (!can_win[stones - square]) {
                can_win[stones] = true;
                break;
            }
        }
    }
    computed_up_to = count;

    return can_win[count];
}