#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The HBRespringController class in Cephei provides conveniences for restarting the system app
/// (usually SpringBoard).

NS_SWIFT_NAME(RespringController)
@interface HBRespringController : NSObject

/// Restart the system app.
///
/// Displays a loading spinner, then returns to the home screen (system remains unlocked).
+ (void)respring;

/// Restart the system app and immediately launch a URL.
///
/// Displays a loading spinner, then launches the specified URL (system remains unlocked).
///
/// @param returnURL The URL to launch after restarting.
+ (void)respringAndReturnTo:(nullable NSURL *)returnURL NS_SWIFT_NAME(respring(returnURL:));

@end

NS_ASSUME_NONNULL_END
