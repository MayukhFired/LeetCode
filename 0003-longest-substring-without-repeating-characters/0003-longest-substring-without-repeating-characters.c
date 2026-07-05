int lengthOfLongestSubstring(char* s) {
  int len = strlen(s);
  if(len == 0){
    return 0;
  }

  int last_seen[128];
  memset(last_seen , -1 , sizeof(last_seen));

  int max_len = 0; 
  int left = 0;

  for(int right = 0; right < len ; right++){
    char current_char = s[right];

    if(last_seen[current_char] >= left){
        left = last_seen[current_char] + 1;
    }

    last_seen[current_char] = right;

    int current_window_size = right - left + 1;
    if(current_window_size > max_len){
        max_len = current_window_size;
    }
  }

  return max_len;
}