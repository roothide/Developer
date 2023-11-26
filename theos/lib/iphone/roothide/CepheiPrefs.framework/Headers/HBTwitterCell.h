#import "HBLinkTableCell.h"

/// The `HBTwitterCell` class in CepheiPrefs is deprecated. Due to changes to the Twitter API, it is
/// no longer feasible for us to include this feature in Cephei. Use `HBLinkTableCell` instead.
///
/// ### Specifier Parameters
/// In addition to the parameters accepted by `HBLinkTableCell`, `HBTwitterCell` accepts the
/// following:
///
/// <table class="graybox">
/// <tr>
/// <td>user</td> <td>Required. The Twitter username of the person.</td>
/// </tr>
/// <tr>
/// <td>iconCircular</td> <td>Optional. Whether the icon should be displayed as a circle. The
/// default from `HBLinkTableCell` is NO, however, `HBTwitterCell` overrides this to YES.</td>
/// </tr>
/// </table>

NS_SWIFT_NAME(TwitterTableCell)
@interface HBTwitterCell : HBLinkTableCell

@end
