class MedianFinder {
public:
    priority_queue<int> firstQ;
    priority_queue<int, vector<int>, greater<int>> secQ;
    MedianFinder() {}

    void addNum(int num) {
        if (firstQ.empty() || firstQ.top() > num) {
            firstQ.push(num);
        } else {
            secQ.push(num);
        }
        if (firstQ.size() > secQ.size() + 1) {
            int x = firstQ.top();
            firstQ.pop();
            secQ.push(x);
        }
        if (firstQ.size() + 1 < secQ.size()) {
            int x = secQ.top();
            secQ.pop();
            firstQ.push(x);
        }
    }
    double findMedian() {
        if (firstQ.size() == secQ.size()) {
            return firstQ.empty() ? 0 : (firstQ.top() + secQ.top()) / 2.0;
        }
        return firstQ.size() > secQ.size() ? firstQ.top() : secQ.top();
    }
};

