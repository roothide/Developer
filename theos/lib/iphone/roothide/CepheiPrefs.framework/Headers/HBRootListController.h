@import UIKit;
#import "HBListController.h"

/// The HBRootListController class in CepheiPrefs provides a list controller class that should
/// be used as the root of the package's settings. It includes two class methods you can override to
/// provide a default message and a URL that the user can share via a sharing button displayed to
/// the right of the navigation bar.
///
/// It is recommended that you use this class even if its current features aren’t appealing in case
/// of future improvements or code that relies on the presence of an HBRootListController.

NS_SWIFT_NAME(RootListController)
@interface HBRootListController : HBListController

// Methods/properties can be found in CepheiPrefs-Swift.h

@end
