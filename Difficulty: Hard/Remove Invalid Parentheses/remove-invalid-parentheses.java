class Solution {
    public List<String> validParenthesis(String s) {
        // code here
         Set<String> ans = new HashSet<>();
        
        Queue<String> q = new LinkedList<>();
        
        q.offer(s);
        Set<String> visited = new HashSet<>();
        visited.add(s);
        
        boolean found = false;
        
        while (!q.isEmpty()) {
            
            String curr = q.poll();
            if (isValid(curr)) {
                ans.add(curr);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < curr.length(); i++) {
                
                char ch = curr.charAt(i);
                if (ch != '(' && ch != ')')
                    continue;
                
                String next = curr.substring(0, i) + curr.substring(i + 1);
                if (!visited.contains(next)) {
                    visited.add(next);
                    q.offer(next);
                }
            }
        }
        List<String> res = new ArrayList<>(ans);
        Collections.sort(res);
        
        return res;
    }
    private boolean isValid(String s) {
        
        int count = 0;
        
        for (char ch : s.toCharArray()) {
            
            if (ch == '(') {
                count++;
            } 
            else if (ch == ')') {
                if (count == 0)
                    return false;
                
                count--;
            }
        }
        return count == 0;
    }
}