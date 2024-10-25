class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folder paths lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> output;
        string prev = ""; // To track the previous folder
        
        for (const string& f : folder) {
            // Add folder to output if it's not a subfolder of the previous one
            if (prev.empty() || f.substr(0, prev.size()) != prev || f[prev.size()] != '/') {
                output.push_back(f);
                prev = f; // Update prev to the current folder
            }
        }
        
        return output;
    }
};
