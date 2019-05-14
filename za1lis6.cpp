  unsigned int h(string s)
{
  unsigned int h,i;

  h = 0;
  for(i = 0; i < s.length(); i++)
    h = h + s[i];
  return h % 10;
}
