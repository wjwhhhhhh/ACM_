int Minimum_representation(string &sec)
{
     int n=sec.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n)
    {
        if (sec[(i + k) % n] == sec[(j + k) % n])
        {
            k++;
        }
        else
        {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j)
                i++;
            k = 0;
        }
    }

    return i = min(i, j);
}