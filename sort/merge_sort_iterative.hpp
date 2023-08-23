void merge(vector<int>& data, int begin, int mid, int end);

void merge_sort(vector<int>& data) {

    for (size_t gap(1); gap < data.size(); gap *= 2) {
        for (size_t left(0); left < data.size(); left += 2 * gap) {
            size_t mid = min(left + gap, data.size()) - 1;
            size_t right = min(left + 2 * gap, data.size()) - 1;
            merge(data, left, mid, right);
        }
    }
}

void merge(vector<int>& data, int begin, int mid, int end) {
    int i(begin), j(mid + 1), k(begin);
    vector<int> temp(end + 1);

    for (;i <= mid && j <= end; k++) {
        if (data[i] < data[j]) {
            temp[k] = data[i];
            i++;
        } else {
            temp[k] = data[j];
            j++;
        }
    }

    for (;i <= mid; i++, k++) {
        temp[k] = data[i];
    }

    for (;j <= end; j++, k++) {
        temp[k] = data[j];
    }

    for (int i(begin); i < k; i++) {
        data[i] = temp[i];
    }
}
