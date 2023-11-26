@import UIKit;

NS_ASSUME_NONNULL_BEGIN

/// The HBSupportController class in CepheiPrefs provides a factory that configures an email
/// composer for package support.
///
/// The resulting view controller should be presented modally; it should not be pushed on a
/// navigation controller stack.

NS_SWIFT_NAME(SupportController)
@interface HBSupportController : NSObject

/// Initialises a Mail composer by using information provided by a bundle and preferences identifier.
///
/// Either a bundle or preferences identifier is required. If both are nil, an exception will be
/// thrown. The email address is derived from the `Author` field of the package’s control file.
/// `HBSupportController` implicitly adds the user’s package listing (output of `dpkg -l`) and the
/// preferences plist as attachments.
///
/// @param bundle A bundle included with the package.
/// @param preferencesIdentifier A preferences identifier that is used by the package.
/// @return A pre-configured email composer.
/// @see `+supportViewControllerForBundle:preferencesIdentifier:sendToEmail:`
+ (UIViewController *)supportViewControllerForBundle:(nullable NSBundle *)bundle preferencesIdentifier:(nullable NSString *)preferencesIdentifier;

/// Initialises a Mail composer by using information provided by a bundle, preferences identifier,
/// and optional email address.
///
/// Either a bundle or preferences identifier is required. If both are nil, an exception will be
/// thrown. If sendToEmail is nil, the email address is derived from the `Author` field of the
/// package’s control file. `HBSupportController` implicitly adds the user’s package listing (output
/// of `dpkg -l`) and the preferences plist as attachments.
///
/// @param bundle A bundle included with the package.
/// @param preferencesIdentifier A preferences identifier that is used by the package.
/// @param sendToEmail The email address to prefill in the To field. Pass nil to use the email
/// address from the package.
/// @return A pre-configured email composer.
+ (UIViewController *)supportViewControllerForBundle:(nullable NSBundle *)bundle preferencesIdentifier:(nullable NSString *)preferencesIdentifier sendToEmail:(nullable NSString *)sendToEmail;

@end

NS_ASSUME_NONNULL_END
