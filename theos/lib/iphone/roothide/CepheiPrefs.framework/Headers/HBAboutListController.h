@import UIKit;
#import "HBListController.h"

/// The HBAboutListController class in CepheiPrefs provides a list controller with functions
/// that would typically be used on an "about" page. It includes two class methods you can override
/// to provide a developer website and donation URL, and a class method to provide an email address
/// so the user can send the developer an email right from the tweak's settings.
///
/// There is a sample of an HBAboutListController implemented in the Cephei demo preferences. See
/// the Cephei readme for details.
///
/// ### Example Usage
/// ```xml
/// <dict>
/// 	<key>cell</key>
/// 	<string>PSLinkCell</string>
/// 	<key>cellClass</key>
/// 	<string>HBLinkTableCell</string>
/// 	<key>label</key>
/// 	<string>Visit Website</string>
/// 	<key>url</key>
/// 	<string>https://hashbang.productions/</string>
/// </dict>
/// <dict>
/// 	<key>cell</key>
/// 	<string>PSGroupCell</string>
/// 	<key>label</key>
/// 	<string>Experiencing issues?</string>
/// </dict>
/// <dict>
/// 	<key>action</key>
/// 	<string>hb_sendSupportEmail</string>
/// 	<key>cell</key>
/// 	<string>PSLinkCell</string>
/// 	<key>label</key>
/// 	<string>Email Support</string>
/// </dict>
/// <dict>
/// 	<key>cell</key>
/// 	<string>PSGroupCell</string>
/// 	<key>footerText</key>
/// 	<string>If you like this tweak, please consider a donation.</string>
/// </dict>
/// <dict>
/// 	<key>cell</key>
/// 	<string>PSLinkCell</string>
/// 	<key>cellClass</key>
/// 	<string>HBLinkTableCell</string>
/// 	<key>label</key>
/// 	<string>Donate</string>
/// 	<key>url</key>
/// 	<string>https://hashbang.productions/donate/</string>
/// </dict>
/// ```

NS_SWIFT_NAME(AboutListController)
@interface HBAboutListController : HBListController

// Methods/properties can be found in CepheiPrefs-Swift.h

@end
