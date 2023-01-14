int bs(vi &v, int key)
{
    int l = 0, h = v.size() - 1, mid;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}