
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if (start > end) {
            return 0;
        }

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int startMonth = stoi(start.substr(0, 2));
        int startDay = stoi(start.substr(3, 2));

        int endMonth = stoi(end.substr(0, 2));
        int endDay = stoi(end.substr(3, 2));

        int startTotal = startDay;
        int endTotal = endDay;

        for (int i = 0; i < startMonth - 1; i++) {
            startTotal += days[i];
        }

        for (int i = 0; i < endMonth - 1; i++) {
            endTotal += days[i];
        }

        return endTotal - startTotal + 1;
    }
};
