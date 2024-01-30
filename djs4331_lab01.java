//Name- Darshil Jigneshkumar Shah
//ID-1002084331
//Language Used: Java 17.0.10
//Os used:Windows


import java.io.File;

public class djs4331_lab01 {
    
    static long djs4331_TotalSize(File directory) {
     
        long djs4331_totalSize = 0;

        // Get list of files and path in the specified folder
        File[] locationFiles = directory.listFiles();
        
        // Check if path is not empty
        if (locationFiles != null) {
            // Iterate through each file or path in the folder
            for (File file : locationFiles) {
                // Check if it's a file
                if (file.isFile()) {
                    // Add file size to variable
                    djs4331_totalSize += file.length();
                } else if (file.isDirectory()) {
                    // Recursively calculate size of subfolder
                    djs4331_totalSize += djs4331_TotalSize(file);
                }
            }
        }
        
        // Return the total size
        return djs4331_totalSize;
    }

    public static void main(String[] args) {
        // Get the current working path
        String djs4331_currentlocation = System.getProperty("user.dir");
     
        File location = new File(djs4331_currentlocation);
        
        // Check if folder exists and is a path
        if (!location.exists() || !location.isDirectory()) {
            System.out.println("Invalid directory OR Folder is Eempty.");
            return;
        }
        
        long totalSize = djs4331_TotalSize(location);
        
        // Print the total size
        System.out.println("Total size of all files in " + location.getAbsolutePath() + " and its sub-folders: " + totalSize + " bytes");
    }
}
