## Swift Package Manager

Medallia Experience Orchestration's Swift Package Manager support is available for use with Xcode. CocoaPods is not required for Swift Package Manager users.

Swift Package Manager support requires Xcode 12.5 or higher.

1. Optionally, if you're adding Medallia Experience Orchestration SDK to a project for the first time, this step can be ignored. If migrating from a CocoaPods-based project, run `pod deintegrate` to remove CocoaPods from your Xcode project. The CocoaPods-generated `.xcworkspace` file can safely be deleted afterward.

2. In Xcode, install the MedalliaMXO framework by navigating to **File > Add Packages…**

3. In the prompt that appears, select the MedalliaMXO GitHub repository:
 
   ```sh
   https://github.com/medallia/mxo-ios-sdk
   ```

   ![MedalliaMXO Add Package](../Distribution%20Supporting%20Files/images/SPM/MedalliaMXOAddPackageURL.png)

2. Select the version of the Medallia Experience Orchestration SDK you want to use. For new projects, we recommend using the newest version of the Medallia Experience Orchestration SDK, which you can find [here](https://permalink.thunderhead.com/mobile-ios/releases). 

   By default, `Up to Next Major` version is selected.
   
   You might need to select your target in this window if there are multiple targets in your workspace. 

   To integrate a specific version of the Medallia Experience Orchestration SDK, simply specify a version number you need. 

   ![MedalliaMXO Choose Package Version](../Distribution%20Supporting%20Files/images/SPM/MedalliaMXOChoosePackage.png)

3. Hit **Add Package** and wait for Xcode to finish verifying and downloading the Swift package into your project.

   ![MedalliaMXO Cloning Package](../Distribution%20Supporting%20Files/images/SPM/MedalliaMXOFetchPackage.png)

4. Choose the MedalliaMXO products you want to include in your app.

   ![MedalliaMXO Select Target](../Distribution%20Supporting%20Files/images/SPM/MedalliaMXOSelectTarget.png)

5. Drag and drop the **_MedalliaMXOBundle.bundle_** to **Copy Bundle Resources** section in your targets.

   ![MedalliaMXO Copy MedalliaMXO Bundle](../Distribution%20Supporting%20Files/images/SPM/MedalliaMXOAddBundleResource.gif)

[Step 2: Configure biometric authentication](../README.md#step-2-configure-biometric-authentication)